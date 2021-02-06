#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else if (b == 1)
    {
        return 1;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int t; 
    cin >> t;
    int maxgcd;

    int* nums = (int*)malloc(t*sizeof(int));
    for (int i = 0; i < t; i ++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < t; i ++)
    {
        if (nums[i] % 2 == 0)
        {
            cout << nums[i] / 2 << endl;
        }
        else
        {
            cout << (nums[i] - 1) / 2 << endl;
        }
        
    }
}