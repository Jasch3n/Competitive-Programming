#include <stdio.h>
#include <stdlib.h>

void resetRemove();
int recurMove(int nums[], int index);
void printArray(int nums[], int size);
void quicksort(int nums[], int low, int high);
int partition(int nums[], int low, int high);
void swap(int *a, int *b);
long long int maxof(long long int a, long long int b);

//represents the maximum possible points by considering the number i
//and all the numbers before i
//so therefore for i = 100000, all the numbers before 100000 will be considered,
//even if they likely will not be all in the number array, it will still be the solution to the problem
long long int dp[100001];
long long int count[100001];

int main()
{
    //taking input from the user
    int n;
    scanf("%d", &n);
    int *nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &nums[i]);
        count[nums[i]] ++;
    }
    //end input section
    
    //quicksort(nums, 0, n);
    dp[0] = 0;
    dp[1] = count[1];
    for (int i = 2; i < 100001; i ++)
    {
        /*obtains the solution by building prior states --
        logic: for each i and the elements before it, one can either choose i
        or not choose i...so taking the maximum of the points corresponding to each
        of the two choices will give the maximum points by consiering i and all
        numbers before it*/
        /*if the number i is not in the array, then it will simply take on the value
        of the last element in dp that is in the array*/
        dp[i] = maxof(dp[i - 1], dp[i - 2] + count[i]*i);
    }

    printf("%lld", dp[100000]);
}


void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition(int nums[], int low, int high)
{
    int pivot = nums[high];
    int index = low - 1;
 
    for (int i = low; i < high; i++)
    {
        if(nums[i] <= pivot)
        {
            index ++;
            swap(&nums[index], &nums[i]);
        }
    }
 
    swap(&nums[index + 1], &nums[high]);
    return (index + 1);
}
 
void quicksort(int nums[], int low, int high)
{
    if (low < high)
    {
        int par = partition(nums, low, high);
 
        quicksort(nums, low, par - 1);
        quicksort(nums, par + 1, high);
    }
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

long long int maxof(long long int a, long long int b)
{
    if (a > b) return a;
    else return b;
}