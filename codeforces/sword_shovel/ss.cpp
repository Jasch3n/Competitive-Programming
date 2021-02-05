#include <iostream>
#include <cmath>

using namespace std;

long howManyEmeralds(long a, long b)
{
    if (a == 0 || b == 0 || (a < 2 && b <2)) return 0;
    else if (a > b)
    {
        if (b * 2 < a)
        {
            return b;
        }
        return (a - b) + floor(2 *(a - 2*(a - b)) / 3);
    } 
    else if (a < b)
    {
        if(a * 2 < b)
        {
            return a;
        }
        return (b - a) + floor(2 *(b - 2*(b - a)) / 3);
    }
    else return 2 * a /3;
}

int main()
{
    int t; cin >> t;

    long* a = (long*)malloc(t*sizeof(long));
    long* b = (long*)malloc(t*sizeof(long));
    for (int i = 0; i < t; i ++)
    {
        cin >> a[i];
        cin >> b[i];
    }

    for (int i = 0; i < t; i ++)
    {
        cout << howManyEmeralds(a[i], b[i]) << endl;
    }
}