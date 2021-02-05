#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <array>

using namespace std;

const int INF = 1e9 + 5;

int main(){
    int t; cin >> t;
    vector<int> answers;

    //load in the boss difficulties
    for(int test = 0;  test < t; test ++){
        int n; cin >> n;
        vector<int> A(n);            //difficulty list
        for(int j = 0; j < n; j ++) {cin >> A[j];}

        vector<array<int, 2>> adj;
        for(int i = 0; i < n; i ++){
            for (int j = i + 2; j <= min(n, i + 4); j ++){
                if(j == i + 2) {adj.push_back}
            }
        }
    }

    for(auto i: answers) cout << i << endl;
}