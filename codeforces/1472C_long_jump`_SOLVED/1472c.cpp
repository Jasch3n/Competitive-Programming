#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calcAnswer(int currIndex, int* a, int* answer, int length);
int currMax=0;

int main() {
    int t; // number of test cases
    cin >> t;
    int* maxAnswers=(int*)malloc(t*sizeof(int));
    
    for (int i=0; i<t; i++) {
        int n; // number of elements in the array
        cin >> n;
        int* a=(int*)malloc(n*sizeof(int));
        for (int j=0; j<n; j++) cin >> a[j];

        int* answers=(int*)calloc(n, sizeof(int));
        for(int j=0; j<n; j++){
            calcAnswer(j,a,answers,n);
        }
        // for(int j=0; j<n; j++){
        //     cout << answers[j] << " ";
        // }
        // cout << endl;
        maxAnswers[i]=currMax;
        currMax=0;
    }    

    for (int i=0; i<t; i++) cout << maxAnswers[i] << endl;
}

int calcAnswer(int currIndex, int* a, int* answer, int length) {
    if (currIndex >= length) return 0;
    else {
        if(answer[currIndex]==0) {
            answer[currIndex]=a[currIndex] + calcAnswer(currIndex+a[currIndex], a, answer, length);
        } 
        if (answer[currIndex]>currMax) {
            currMax=answer[currIndex];
        }
        return answer[currIndex];
    }
}