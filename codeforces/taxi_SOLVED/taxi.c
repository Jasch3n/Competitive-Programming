#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int cntFour;
int cntThree;
int cntTwo;
int cntOne;
int cntTaxi = 0;

void count(int* nums, int size);



void count(int* nums, int size)
{
    for (int i = 0; i < size; i ++)
    {
        if (nums[i] == 4) cntFour ++;
        else if(nums[i] == 3) cntThree ++;
        else if(nums[i] == 2) cntTwo ++;
        else cntOne ++;
    }   
}

void loadFour()
{
    cntTaxi += cntFour;
}

//load all the groups of threes
void loadThree()
{
    cntTaxi += cntThree;
}

//combine into groups of two groups of twos
void loadTwo()
{
    if (cntTwo > 1)
    {
        cntTaxi += floor(cntTwo / 2);
        cntTwo = cntTwo%2;
    }
}

//combine the ones with the available threes
void loadOne()
{
    cntOne -= cntThree;
}

//there should be only free groups of Two and One at this point
// specifically there should only be either one group of two or zero group of two
void loadLeftover()
{   
    if(cntOne > 0 && cntTwo > 0)
    {
        cntTaxi += cntTwo; cntOne -= 2; cntTwo = 0;
        if (cntOne > 0)
        {
            cntTaxi += ceil((float)cntOne / (float)4);
        }
    }
    else if (cntOne > 0 && cntTwo == 0)
    {
        if (cntOne % 4 == 0) cntTaxi += cntOne/4;
        else cntTaxi += ceil((float)cntOne / (float)4);
    }
    else if (cntOne < 1 && cntTwo > 0) cntTaxi += cntTwo; 
    else return;
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int* nums = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &nums[i]);
    }

    cntFour = 0; cntThree = 0; cntTwo = 0; cntOne = 0;
    count(nums, n);
    loadFour();
    loadThree();
    loadTwo();
    loadOne();
    loadLeftover();
    
    printf("%i", cntTaxi);
    
    return 0;
}