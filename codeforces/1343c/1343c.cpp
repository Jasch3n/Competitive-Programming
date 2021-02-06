#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calcLength(int* A, int* memLen, int index, int n);
long long int calcSum(int* A, long long int* memSum, int index, int n);
int findNextAltIndex(int* A, int size, int index);

int main()
{
    int t; cin>>t; // number of test cases
    long long int* answers=(long long int*)calloc(t,sizeof(long long int));

    for (int i=0; i<t; i++) {
        int n; cin>>n;
        int* A=(int*)malloc(n*sizeof(int));
        for (int ii=0; ii<n; ii++) cin>>A[ii];

        int* memLen=(int*)calloc(n,sizeof(int));
        // memLen[i] will be the length of the longest alternating subsequence
        // in A that starts at A[i]

        int k=-1;
        
        for (int ii=0; ii<n; ii++) {
            int currLength=calcLength(A,memLen,ii,n);
            if (currLength>k) k=currLength;
        }


        long long int** dpSum = new long long int*[n];
        for (int j=0;j<n;j++) dpSum[j] = new long long int[k+1];

        bool** lastSign = new bool*[n];
        for (int j=0;j<n;j++) lastSign[j] = new bool[k+1];

        // initialize the first two columns of dpSum
        for (int j=0; j<n; j++) dpSum[j][0]=0;
        for (int j=0; j<n; j++) { dpSum[j][1]=A[j]; lastSign[j][1]=A[j]>0; }
        
        for (int y=2; y<k+1; y++) {
            for (int x=0; x<n-1; x++) {
                if (x+1 >= y){
                    if (A[x+1] > 0 != lastSign[x][y-1]) {
                        dpSum[x+1][y]=0;
                    }
                    else {
                        dpSum[x+1][y]=A[x+1];
                    }
                    lastSign[x+1][y]=A[x+1]>0;  

                } else dpSum[x][y]=0;
            }
        }

        for (int x=0; x<n; x++) {
            for (int y=0; y<k+1; y++) {
                cout << dpSum[x][y] << " ";
            }
            cout<<endl;
        }

    }

    // for(int i=0; i<t; i++) cout<<answers[i]<<" ";
}

int findNextAltIndex(int* A, int size, int index) {
    for(int i=index; i<size; i++) {
        if ((A[index]>0 && A[i]<0) || (A[index]<0 && A[i]>0)) 
            return i;
    }
    return -1;
}

int calcLength(int* A, int* memLen, int index, int n) {
    int nextIndex=findNextAltIndex(A,n,index);
    if (nextIndex == -1) memLen[index]=1; // no next alternating element is found
    else if (memLen[index]!=0) return memLen[index]; // memoization already initialized
    // 1 + solution to subproblem. assuming a subproblem still exists
    else memLen[index]=1+calcLength(A, memLen, nextIndex, n);
    // cout<<"NEXT ALT INDEX: "<<nextIndex<<endl;
    // for (int ii=0; ii<n; ii++) cout << memLen[ii] << " "; cout<<endl;
    return memLen[index];

}
