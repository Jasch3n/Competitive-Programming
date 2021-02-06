#include <stdio.h>
#include <stdlib.h>

void printBoard(int** board, int m, int n); 

int main()
{
    int m, n, counter = 0;
    scanf("%d", &m);
    scanf("%d", &n);
    //code to create a m x n matrix filled with zeros
    int** board = (int **)malloc(m*sizeof(int* ));
    for (int i = 0; i < m; i++){
        board[i] = (int*)malloc(n*sizeof(int));
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j ++){
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j ++)
        {
            if (board[i][j] == 0 && board[i][j+1] == 0)
            {
                board[i][j] = 1;
                board[i][j+1] = 1;  
                counter ++;
            }
        }
    }

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (board[i][j] == 0 && board[i + 1][j] == 0)
            {
                board[i][j] = 1;
                board[i+1][j] = 1;
                counter ++;
            }
        }
    }

    //printBoard(board, m, n);

    printf("%i", counter);

}

void printBoard(int** board, int m, int n)
{
        
    printf("\nTHE DOMINO BOARD: \n"); 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j ++)
        {
            printf("%i ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}