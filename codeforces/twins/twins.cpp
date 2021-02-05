#include <iostream>
using namespace std;

void display (int* arr, int length)
{
    for (int i = 0; i < length; i ++)
    {
        cout << arr[i] << " " << endl;
    }
}

void swapp(int* arr, int a, int b)
{
    int temp = *(arr + b);
    *(arr + b) = *(arr + a);
    *(arr + a) = temp;
}

void InsertionSort (int* arr, int length)
{
    for (int i = 1; i < length; i ++)
    {
        int temp = arr[i];
        for (int j = i; j > 0; j --)
        {
            if(arr[j] < arr[j - 1])
            {
                swapp(arr, j, j-1);
            }
        }
    }
}

int sum(int* arr, int start, int end)
{
    int temp = 0;
    for (int i = start; i < end; i ++)
    {
        temp += arr[i];
    }
    return temp;
}

int main()
{
    int N;
    cin >> N;
    int* a = (int*)malloc(N * sizeof(int));
    for (int i = 0 ; i < N; i ++)
    {
        cin >> a[i];
    }
    InsertionSort(a, N);
    
    int total = sum(a, 0, N);
    int crawler = 1;
    for (int i = N - 1; i >= 0; i --)
    {
        int mySum = sum(a, N - crawler, N);
        int theirSum = total - mySum;
        if (mySum > theirSum)
        {
            cout << crawler;
            return 0;
        }
        else
        {
            crawler ++;
        }
        
    }
}



