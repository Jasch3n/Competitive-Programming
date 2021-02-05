#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long N, D, output = 0;
    cin >> N;
    cin >> D;

    long* X = (long*)malloc(N*sizeof(long));
    long* Y = (long*)malloc(N*sizeof(long));
    double* distances = (double*)malloc(N*sizeof(double));

    for (long i = 0; i < N; i ++){
        cin >> X[i];
        //prlongf("X[%i] = %i\n", i, X[i]);
        cin >> Y[i];
        //prlongf("Y[%i] = %i\n", i, Y[i]);
    }

    for (long i = 0; i < N; i ++){
        distances[i] = sqrt(pow(X[i],2) + pow(Y[i],2));
        //cout << (distances[i]) << endl;
        if (distances[i] <= D){
            output ++;
        }
    }
    
    cout << output;
}