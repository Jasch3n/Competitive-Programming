#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100], answer = 0;


int sum(int *arr, int length)
{
    int ans = 0;
    for (int i = 0; i < length; i++)
    {
        ans += arr[i];
    }
    return ans;
}

int solve(int i, int j, int* arr, int length)
{
    if(i == j)
    {
        if(arr[i] == 1) return sum(arr, length) - 1;
        if(arr[i] == 0) return sum(arr, length) + 1;
    }
    if(arr[j] == 0 && i <= j) return 1 + solve(i, j - 1, arr, length);
    if(arr[j] == 1 && i <= j) return solve(i, j - 1, arr, length) - 1;
    else return -1;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            int temp =  solve(i, j, a, n); //cout << temp << " i =" << i << " j=" << j << endl;
            answer = max(answer, temp);
        }
    }

    cout << answer;
}