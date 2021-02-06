#include <iostream> 

using namespace std;
void printArray(long long int* nums, int size);
void swap(long long int*a, long long int *b);
int partition(long long int* nums, int low, int high);
void quicksort(long long int* nums, int low, int high);


int main()
{
    long long int maxCap = 0;
    long long int secMaxCap = 0;
    long long int sumRemain = 0;
    int n;
    cin >> n;
    long long int* remain = (long long int*)malloc(n*sizeof(long long int)), 
                   *capacity = (long long int*)malloc(n*sizeof(long long int));


    // load the remaining volumes and capacities of each can
    for (int i = 0; i < n; i ++)
    {
        cin >> remain[i];
    }
    for ( int i = 0; i < n; i ++)
    {
        cin >> capacity[i];
    }
    for (int i = 0; i < n; i++)
    {
        int temp = capacity[i];
        if (temp > maxCap)
        {
            secMaxCap = maxCap;
            maxCap = temp;
        }
        else if (temp > secMaxCap)
        {
            secMaxCap = temp;
        }
    }

    //sort the loaded arrays in increasing order
    // quicksort(capacity, 0, n);
    // cout << "The remain array is:" << endl;
    // printArray(remain, n);
    // cout << "The capacity array is:" << endl;
    // printArray(capacity, n);
    // cout << endl;


    //obtaining the sum of all the remaining volume
    for (int i = 0; i < n; i ++)
    {
        sumRemain += remain[i];
    }
    //cout << sumRemain;

    // bool found = 0;
    // for (int i = 0; i < n; i ++)
    // {
    //     for (int j = 0; j < n; j ++)
    //     {
    //         if ( i != j && capacity[i] + capacity[j] >= sumRemain) 
    //         {
    //             cout <<"\nYES" << endl;
    //             return 0;
    //         }
    //     }
    // }
    // cout << maxCap << endl;
    // cout << secMaxCap << endl;
    // cout << maxCap + secMaxCap;
    if (maxCap + secMaxCap >= sumRemain) 
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;

    // for (int i = n - 1; i >= 1; i --)
    // {
    //     //checking to see if pairs of containers with the largest volumes can contain the sum
    //     if (capacity[i] + capacity[i - 1] < sumRemain) 
    //     {
    //         cout << "NO";
    //         return 0;
    //     }
    //     else if (capacity[i] + capacity [i - 1] >= sumRemain)
    //     {
    //         cout << "YES";
    //         return 0;
    //     }
    //     else
    //     {
    //         cout << "NO";
    //         return 0;
    //     }
    // }

}


void printArray(long long int* nums, int size)
{
    for (int i = 0; i < size; i ++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void swap(long long int*a, long long int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(long long int* nums, int low, int high)
{
    long long int pivot = nums[high];
    int crawler = low - 1;

    for(int j = low; j < high; j ++)
    {
        if (nums[j] <= pivot)
        {
            crawler ++;
            swap(&nums[crawler], &nums[j]);

        }
    }
    swap(&nums[high], &nums[crawler + 1]);
    return crawler + 1;
}

void quicksort(long long int* nums, int low, int high)
{
    if (low < high)
    {
        int pi = partition(nums, low, high);
        quicksort(nums, low, pi - 1);
        quicksort(nums, pi + 1, high);
    }
}