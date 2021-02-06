#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n; // number of days
    cin >> n;
    int k; // number of necessary walks in consecutive days
    cin >> k;
    int* A = (int*)malloc(n * sizeof(int)); // array of number of planned walks for each day
    int answer=0;
    int* B = (int*)malloc(n*sizeof(int)); // array of answers

    for (int i=0; i<n; i++) cin >> A[i]; // load in the days input

    // cout << n << " " << k << endl;
    // for (int i=0; i<n; i++) cout << A[i];
    
    for (int i=0; i<n; i++) {
        if(i==0) {
            B[i] = A[i];
            continue;
        } else {
            if (A[i]+B[i-1] < k) {
                // least amount of walks is not satisfied
                // cout << "Not Satisfied" << endl;
                int diff = k - (A[i] + B[i-1]);
                // cout << "DIFF: " << diff << endl;
                B[i] = A[i]+diff;
                answer += diff;

            } else {
                // least amount of walks is satisfied already,
                // no point in adding more days
                B[i] = A[i];
            }
        }
    }

    cout << answer << endl;
    for (int i=0; i<n; i++) cout << B[i] << " "; // load in the days input

}