# include "head.h"


int check_queen(char **av, int row, int col)
{
    return(check_bishop(av, row, col) || check_rock(av, row, col));
}