#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t; cin >> t;

    long* n = (long*)malloc(t*sizeof(long));
    long* k = (long*)malloc(t*sizeof(long));
    for (int i = 0; i < t; i ++)
    {
        cin >> n[i]; cin >> k[i];
    }

    for (int i = 0; i < t; i ++)
    {
        long N = ceil( (long double)k[i]/ (long double)(n[i]-1)) * n[i];
        long Nminus = N - n[i];
        long ansTemp = 0;
        if (k[i]%(n[i]-1) != 0)
            ansTemp = Nminus + k[i]%(n[i]-1);
        else
            ansTemp = Nminus + (n[i] - 1);
        cout << ansTemp << endl;
    }
}