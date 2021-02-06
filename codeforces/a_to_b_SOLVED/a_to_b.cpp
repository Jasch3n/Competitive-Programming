#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long int steps = 0;

void printVector (vector<long long int> v)
{
    for (vector<long long int>::const_iterator i= v.begin(); i!= v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

long long int recurse(long long int a, long long int b, vector<long long int> &v)
{
    steps ++;
    v.push_back(a);
    if (a > b)
    {
        steps --;
        v.pop_back();
        return -1;
    }
    else if (a == b)
    {
        return b;
    }
    else
    {
        long long int left = recurse(10*a + 1, b, v);
        if (left != -1)
        { 
            return 1;
        }
        long long int right = recurse(2*a, b, v);
        if(right != -1)
        { 
            return 1;
        }
    }
    steps --;
    v.pop_back();
    return -1;
}

int main()
{
    long long int a; cin >> a;
    long long int b; cin >> b;

    vector<long long int> pathRecord;
    int found = recurse(a, b, pathRecord);
    if (found == 1)
    {
        cout << "YES" << endl;
        cout << pathRecord.size() << endl;
        printVector(pathRecord);
    }
    else
    {
        cout << "NO";
    }
    
}