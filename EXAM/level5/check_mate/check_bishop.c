//trace
//   2 [\] [.] [.] [/] 1
//     [.] [2] [1] [.]
//     [.] [1] [2] [.]
//   3 [/] [.] [.] [\] 4
int check_bishop(char **av, int row, int col)
{
    int i;
    int j;
    int access = 1;

//see trace "/\" 
//           /\
//           /\

    i = row - 1;
    j = col + 1;
    //top right  "/"  from [3 to 1]
    while((i >= 0 && j >= 0) && (av[i] && av[i][j]))
    {
        if(av[i][j] == 'K')
            return 1;
        else if(av[i][j] != '.')
            break;
        i--;
        j++;
    }
    //down left "/" from [1 to 3]
    i = row + 1;
    j = col - 1;
    while((i >= 0 && j >= 0) && (av[i] && av[i][j]))
    {
        if(av[i][j] == 'K')
            return 1;
        else if(av[i][j] != '.')
            break;
        i++;
        j--;
    }
    //top left "\" from [4 to 2]
    i = row - 1;
    j = col - 1;
    while((i >= 0 && j >= 0) && (av[i] && av[i][j]))
    {
        if(av[i][j] == 'K')
            return 1;
        else if(av[i][j] != '.')
            break;
        i--;
        j--;
    }

    //down right "\" from [2 to 4]
    i = row + 1;
    j = col + 1;
    while((i >= 0 && j >= 0) && (av[i] && av[i][j]))
    {
        if(av[i][j] == 'K')
            return 1;
        else if(av[i][j] != '.')
            break;
        i++;
        j++;
    }
    return 0;
}

// int main()
// {
//     char *av[9];

//     av[0] = "........";
//     av[1] = "..B....."; 
//     av[2] = ".....K..";
//     av[3] = "....P...";
//     av[4] = ".....K..";
//     av[5] = "........";
//     av[6] = "........";
//     av[7] = "........";
//     av[8] = NULL;

//     if(check_bishop(av, 1, 2))
//         printf("check\n");
//     else
//         printf("safe\n");
// }
