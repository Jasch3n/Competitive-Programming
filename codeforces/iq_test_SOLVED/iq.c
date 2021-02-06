#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

bool arrIsEven(int* nums);

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    scanf("%d", &n);
    int* nums = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &nums[i]);
    }

    if (arrIsEven(nums))
    {
        for (int i = 0; i < n; i ++)
        {
            if (nums[i] % 2 == 1)
            {
                printf("%i", i + 1);
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i ++)
        {
            if (nums[i] % 2 == 0)
            {
                printf("%i", i + 1);
                break;
            }
        }
    }

    return 0;
}

bool arrIsEven(int* nums)
{
    int cntEven = 0;
    int cntOdd = 0;
    for (int i = 0; i < 3; i ++)
    {
        if (nums[i] % 2 == 0) cntEven ++;
        else cntOdd ++;
    }

    return (cntEven >= 2);
}