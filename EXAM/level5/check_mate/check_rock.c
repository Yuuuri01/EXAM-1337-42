int check_rock(char **av, int row, int col)
{
    int i;
    int j;

    //up row
    i = row - 1;
    j = col;
    while(i >= 0 && av[i])
    {
        if(av[i][j] == 'K')
            return 1;
        else if(av[i][j] != '.' && av[i][j] != 'R')
            break;
        i--;
    }
    //row down
    i = row + 1;
    j = col;
    while(i >= 0 && av[i])
    {
        if(av[i][j] == 'K')
            return 1;
        else if(av[i][j] != '.' && av[i][j] != 'R')
            break;
        i++;
    }
    //col left to right
    i = row;
    j = col + 1;
    while(j >= 0 && av[i][j])
    {
        if(av[i][j] == 'K')
            return 1;
        else if(av[i][j] != '.' && av[i][j] != 'R')
            break;
        j++;
    }
    //col right to left
    i = row;
    j = col - 1;
    while(j >= 0 && av[i][j])
    {
        if(av[i][j] == 'K')
            return 1;
        else if(av[i][j] != '.' && av[i][j] != 'R')
            break;
        j--;
    }
    return 0;
}
