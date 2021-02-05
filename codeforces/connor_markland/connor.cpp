#include <iostream>
#include <cmath>

using namespace std;

bool isInK(long *K, long k, long target)
{
    for (long i = 0; i < k; i ++)
    {
        if (K[i] == target) return true;
    }
    return false;
}

int main()
{
    int t; cin >> t;
    long * ans = (long*) malloc (t*sizeof(long));
    for (int i = 0; i < t; i ++)
    {
        long n; cin >> n; 
        long s; cin >> s;
        long k; cin >> k;

        long* K = (long*)malloc(k*sizeof(long));
        for (int w = 0; w < k; w ++)
        {
            cin >> K[w];
        }
        if (!isInK(K, k, s))
        {
            ans[i] = 0;
            continue;
        } 

        long rightBest = 100000005, leftBest = 100000005;
        for (long j = s; j <= n; j ++)
        {
            if (!isInK(K,k,j))
            {
                rightBest = (j - s);
                break;
            } 
            
        }
        for (long j = s - 1; j >= 1; j --)
        {
            if(!isInK(K,k,j))
            {
                leftBest = ( s - j );
                break;
            }
            
        }
        ans[i] = (rightBest >= leftBest) ? leftBest : rightBest;
    }

    for (int i = 0; i < t; i ++)
    {
        cout << ans[i] << endl;
    }
}