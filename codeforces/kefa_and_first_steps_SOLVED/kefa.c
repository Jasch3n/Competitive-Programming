#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isNonDec(int* nums, int start, int end);
int steps(int *nums, int start, int size, int *memo);
void printArray(int nums[], int size);
 
int main(int argc, char const *argv[])
{
    /* code */
    int maxSteps = 0;
    int n;
    scanf("%d", &n);
    int *nums = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &nums[i]);
    }
    //printArray(nums,n);
    //printf("%d", isNonDec(nums, 0, n));

    int temp = 1;
    for (int i = 0; i < n - 1; i ++)
    {
        
        if(nums[i] > nums[i + 1])
        {
            temp = 1;
        }

        else
        {
            temp ++;
        }
        if(temp > maxSteps) maxSteps = temp;
    }
    //printf("isNonDec == %d \n", isNonDec(nums, 2, 4));

    //printf("\n");
    if(temp > maxSteps) maxSteps = temp;
    printf("%i", maxSteps);
    return 0;
}

int steps(int *nums, int start, int size, int *memo)
{
    if (start == 0)
    {
        for (int i = size - 1; i >= start; i --)
        {
            if (isNonDec(nums, start, i))
            {
                memo[start] = (i - start + 1);
                return memo[start];
            } 
        }
    }
    else if (nums[start] > nums[start - 1])
    {
        memo[start] = memo[start - 1] - 1;
        return memo[start];
    }
    else if (nums[start] == nums[start - 1])
    {
        memo[start] = memo[start - 1];
        return memo[start];
    }
    else
    {
        for (int i = size - 1; i >= start; i --)
        {
            if (isNonDec(nums, start, i))
            {
                memo[start] = (i - start + 1);
                return memo[start];
            } 
        }
    }
    return 0;
}

bool isNonDec(int* nums, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (nums[i] > nums[i + 1]) return 0;
    }
    return 1;
}

void printArray(int nums[], int size)
{
    printf("\nthe array is: \n");
    for(int i = 0; i < size; i ++)
    {
        printf("%i ", nums[i]);
    }
    printf("\n");
}
