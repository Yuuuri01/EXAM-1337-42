# include <stdio.h>


int check_bishop(char **av, int row, int col)
{
    int j;
    int i = 0;
    int block = 1;
    int pass = 0;
    char c = 0;
    while(av[i] && block)
    {
        j = 0;
        while(av[i][j])
        {
            if(block && (av[i][j] == 'P' || av[i][j] == 'Q' || av[i][j] == 'B' || av[i][j] == 'R' || av[i][j] == 'K'))
            {
                if((j - i == col - row) || (i + j == row + col))
                {
                    c = av[i][j];
                    block = 0;
                }
            }
            j++;
        }
        i++;
    }
    if(c == 'K')
        pass = 1;
    else if(c == 'B')
        pass = 2;
    i = 0;
    while(av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if((av[i][j] == 'R' || av[i][j] == 'P') && (i + j == row + col || j - i == col - row))
            {
                if(c != 'R' && c != 'P')
                    pass = 1;
                else
                    return 0;
            }
            else if((pass == 2 && av[i][j] == 'K') || (pass == 1 && av[i][j] == 'B'))
            {
                if((i + j == row + col) || (j - i == col - row))
                    return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}
