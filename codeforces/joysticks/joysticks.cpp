#include <iostream>
using namespace std;

int a, b;

int solve(int a, int b)
{
    if (a == 0 || b == 0) return 0;
    if (a > b) return 1 + solve(a - 2, b + 1);
    if (a < b) return 1 + solve(a + 1, b - 2); 
    if (a == b && (a != 1 || b != 1)) return 1 + solve(a - 2, b + 1);
    else return 0;
}

int main()
{
    cin >> a >> b;
    cout << solve(a , b);
}