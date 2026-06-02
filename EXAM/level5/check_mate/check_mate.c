# include <unistd.h>
# include "head.h"


int main(int ac, char **av)
{
    if(ac >= 2)
    {
        int i = 1;
        int j;
        int access = 0;
        while(av[i])
        {
            j = 0;
            while(av[i][j])
            {
                if(av[i][j] == 'R')
                {
                    if(check_rock(av, i, j))
                        access = 1;
                }
                else if(av[i][j] == 'B')
                {
                    if(check_bishop(av, i , j))
                        access = 1;
                }
                else if(av[i][j] == 'P')
                {
                    if(check_pawn(av, i, j))
                        access = 1;
                }
                else if(av[i][j] == 'Q')
                    if(check_queen(av, i, j))
                        access = 1;
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