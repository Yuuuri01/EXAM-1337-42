//trace
//   2 [\] [.] [.] [/] 1
//     [.] [2] [1] [.]
//     [.] [1] [2] [.]
//   3 [/] [.] [.] [\] 4
int check_bishop(char **av, int row, int col)
{
    //see trace "/\" 
    //           ||
    //           ||
    int i;
    int j;

    //top right  "/"  from [3 to 1]
    i = row - 1;
    j = col + 1;
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
    while((j >= 0 && i >= 0) && (av[i] && av[i][j]))
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
