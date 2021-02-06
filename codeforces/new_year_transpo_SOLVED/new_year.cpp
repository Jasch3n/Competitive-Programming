#include<iostream>
using namespace std;

void expand(pair<int,int> stateTuple, int goal, int* a)
{
    int nextStop = stateTuple.first + stateTuple.second;
    if (nextStop > goal)
    {
        cout << "NO"; return;
    }
    else if (nextStop < goal)
    {
        expand(make_pair(nextStop, a[nextStop]), goal, a);
    }
    else
    {
        cout << "YES";
        return;
    }
    
}

int main()
{
    int n; cin >> n;
    int t; cin >> t;

    int* a = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n - 1; i ++)
    {
        cin >> a[i];
    }

    expand(make_pair(0, a[0]), t - 1, a);
}

