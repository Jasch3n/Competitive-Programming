#include <iostream>
#include <cmath>

using namespace std;

int reduceToOne (long n)
{
    int alpha = 0;
    int beta = 0;
    while(n%3 == 0)
    {
        n = n/3;
        beta ++;
    }
    for (int i = 0; i <= beta; i++)
    {
        if (n == pow(2, beta - i))
        {
            return (i + beta);
        }
    }
    return -1;
}


int main()
{
    int t;
    cin >> t;

    long* nums = (long*)malloc(t*sizeof(long));
    for (int i = 0; i < t; i ++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < t; i++)
    {
        cout << reduceToOne(nums[i]) << endl;
    }
}
