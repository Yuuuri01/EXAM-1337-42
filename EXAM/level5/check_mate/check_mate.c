# include <unistd.h>
# include "head.h"

int main(int ac, char **av)
{
    if(ac >= 2)
    {
        char **board = av + 1;
        int i = 0;
        int j;
        int access = 0;
        while(board[i])
        {
            j = 0;
            while(board[i][j])
            {
                if(board[i][j] == 'R')
                    access = check_rock(board, i, j);
                else if(board[i][j] == 'B')
                    access = check_bishop(board, i , j);
                else if(board[i][j] == 'P')
                    access = check_pawn(board, i, j);
                else if(board[i][j] == 'Q')
                    access = check_queen(board, i, j);
                if(access)
                {
                    write(1, "Success\n", 8);
                    return 0;
                }
                j++;
            }
            i++;
        }
        write(1, "Fail", 4);
    }
    write(1, "\n", 1);
}

// int main()
// {
//     char *av[5];

//     av[0] = "....";
//     av[1] = "....";
//     av[2] = "..Q.";
//     av[3] = "K...";
//     av[4] = NULL;
    

//     if(check_queen(av, 2, 2))
//         printf("check\n");
//     else
//         printf("safe\n");
// }

    //   0     1     2     3   4
    //  -------------------------
    // 0[.]   [.]   [.]   [.]  [.]
    // 1[.]   [.]   [.]   [.]  [.]
    // 2[.]   [.]   [B]   [.]  [.]
    // 3[.]   [.]   [.]   [.]  [.]
    // 4[K]   [.]   [.]   [.]  [.]


    // . .
    // . K 


    //R... 
    //.K.. 
    //..P. 
    //....
