#include <iostream> 
#include <cmath>

using namespace std;

long long int nthNum (long long int n);

int main()
{
    int K;
    cin >> K;

    long long int crawler = 7;

    for (int i = 0; i < 100; i ++)
    {
        long long int temp = nthNum(crawler);
        cout << temp << endl;
        crawler = temp;
    }
}

long long int nthNum (long long int nMinusOneNum)
{
    return 10 * nMinusOneNum + 7;
}