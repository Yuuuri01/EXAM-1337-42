
int check_rock(char **av, int row, int col)
{
    if(col < 0 || row < 0)
        return 0;

    int i = 0;
    int j;
    while(av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if(av[i][j] != '.' && ((i == row && j != col) || (i != row && j == col)))
            {
                if(av[i][j] == 'K')
                    return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}
