
int check_pawn(char **av, int row, int col)
{
    if(row == 0)
        return 0;

    if(col == 0)
    {
        if(av[row - 1][col + 1] == 'K')
            return 1;
    }
    else if(!av[row][col + 1])
    {
        if(av[row - 1][col - 1] == 'K')
            return 1;
    }
    else if(col > 0)
    {
        if((av[row - 1][col - 1] == 'K') || (av[row - 1][col + 1] == 'K'))
            return 1;
    }
    return 0;
}
