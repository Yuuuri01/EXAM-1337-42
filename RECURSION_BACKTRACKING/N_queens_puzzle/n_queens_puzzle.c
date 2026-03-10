# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb == 0)
    {
        ft_putchar('0');
        return;
    }
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}
int isSafe(int n ,int Q[n], int row, int col)
{
    int i = 0;
    while(i < row)
    {
        if(Q[i] == col)
            return 0;
        if(Q[i] + i == row + col)
            return 0;
        if(Q[i] - i == col - row)
            return 0;

        i++;
    }
    return 1;
}
void print_solution(int n, int Q[n])
{
    int i = 0;
    while(i < n)
    {
        ft_putnbr(Q[i++]);
    }
    printf("\n");
}
int solve_n_queen(int n, int Q[n], int row, int *counter)
{
    if(n == row)
    {
        print_solution(n, Q);
        (*counter)++;
    }
    int col = 0;
    while(col < n)
    {
        if(isSafe(n, Q, row, col))//choice //recursion //backtrack
        {
            Q[row] = col;
            solve_n_queen(n , Q, row + 1, counter);
        }
        col++;
    }
    return *counter;
}
void N_queens_problem()
{
    int row = 0;
    int n = 4;
    int Q[n];
    int count = solve_n_queen(n, Q, row, &count);
    ft_putnbr(count);
}
/*
int main()
{
    N_queens_problem();
    ft_putchar('\n');
}
*/

