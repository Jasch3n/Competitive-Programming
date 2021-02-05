#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void printMatrix(int **forces, int n);
bool isEqui(int **forces, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int **forces = (int **)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        forces[i] = (int*)malloc(3*sizeof(int));
    }

    for(int i = 0; i < n; i ++)
    {
        for (int j = 0; j < 3; j ++)
        {
            scanf("%d", &forces[i][j]);
        }
    }
    
    //printMatrix(forces, n);

    if(isEqui(forces, n))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    

}

void printMatrix(int **forces, int n)
{
    printf("\nTHE MATRIX: \n");
    for(int i = 0; i < n; i ++)
    {
        for (int j = 0; j < 3; j ++)
        {
            printf("%i ", forces[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isEqui(int **forces, int n)
{
    int xSum = 0;
    int ySum = 0;
    int zSum = 0;
    for(int j = 0; j < 3; j ++)
    {
        for(int i = 0; i < n; i ++)
        {
            if(j == 0)
            {
                xSum += forces[i][j];
            }
            else if(j == 1)
            {
                ySum += forces[i][j];
            }
            else
            {
                zSum += forces[i][j];
            }
            
        }
    }

    return(xSum == 0 && ySum == 0 && zSum == 0);
}