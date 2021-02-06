#include <iostream> 
#include <algorithm>

using namespace std;

int firstBiggestIndex (int* arr, int target, int length)        //binary search for the index of the first element that is strictly greater than target
{
    int start = 0;

    int end = length;
    int ans = -1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if (arr[mid] <= target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int* x = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n ; i ++)
    {
        cin >> x[i];
    }
    sort(x, x + n);

    int q;
    cin >> q;

    int* m = (int*)malloc(q*sizeof(int));
    for (int i = 0; i < q; i ++)
    {
        cin >> m[i];
    }

    for (int i = 0 ; i < q; i ++)
    {
        if (m[i] < x[n - 1])
            cout << firstBiggestIndex(x, m[i], n - 1) << endl;
        else cout << n << endl;
        
    }
}