#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin>>n;
    long long * values=(long long*)calloc(n, sizeof(long long));
    long long * sumOne=(long long*)calloc(n, sizeof(long long));
    long long * sumTwo=(long long*)calloc(n, sizeof(long long));

    for(int i =0; i<n; i++) {
        int vi; cin>>vi;
        values[i]=vi;
        (i==0)? sumOne[i]=vi : sumOne[i]=sumOne[i-1]+vi;
    }
    sort(values, values+n); sumTwo[0]=values[0];
    for(int i=1; i<n; i++) {
        sumTwo[i]=sumTwo[i-1]+values[i];
    }
    int m; cin>>m; 
    long long * answers = (long long*)calloc(m, sizeof(long long));
    for (int i=0; i<m; i++){
        int type; cin>>type;
        int l; cin >> l; 
        int r; cin >> r;
        if (type == 1) {
            long long a = (l-2 >=0)?sumOne[r-1] - sumOne[l-2]:sumOne[r-1];
            answers[i]=a;
        } else {
            long long a = (l-2 >=0)?sumTwo[r-1] - sumTwo[l-2]:sumTwo[r-1];
            answers[i]=a;

        }
    }

    for (int i=0; i<m; i++) cout << answers[i] << endl;


}