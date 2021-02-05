#include <iostream> 

using namespace std;


int main()
{
    int n;
    cin >> n;

    long* x = (long*)malloc(n*sizeof(long));
    for (int i = 0; i < n; i ++)
    {
        cin >> x[i];
    }

    int minIndexReached = (n - 1) - x[n - 1];
    int survivalCnt = n;
    for (int i = n - 2; i >= 0; i --)
    {
        if (i >= minIndexReached)
        {
            survivalCnt --;
        }
        if (i - x[i] < minIndexReached)
        {
            minIndexReached = i - x[i];
        }
    }

    cout << survivalCnt;
}