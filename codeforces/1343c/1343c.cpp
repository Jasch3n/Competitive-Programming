#include <iostream>
#include <vector>
#include <string>
#include <vector>

using namespace std;

int calcLength(int* A, int* memLen, int index, int n);
long long int calcSum(int* A, long long int* memSum, int index, int n);
vector<int> findAllAltIndex(int* A, int size, int index);
long long int solve(int* A, long long int** dp, int n, int index, int k, bool** initialized, int* memLen);
long long int arbitraryMax(vector<long long int> nums);

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

        // cout << "MAX LENGTH = " << k << endl;
        long long int** dp = new long long int*[n]; 
        for (int j=0;j<n;j++) dp[j] = new long long int[k+1];

        bool** initialized = new bool*[n]; 
        for (int j=0;j<n;j++) initialized[j] = new bool[k+1];
        for (int j=0;j<n;j++) { for (int jj=0;jj<k+1;jj++) { initialized[j][jj]=false; } }

        
        long long int currMaxSum; bool currMaxSumFound=false;
        for (int j=0; j<n; j++) {
            if (memLen[j]==k) {
                // cout << "CANDIDATE: " << A[j] <<endl;
                long long int thisMaxSum=solve(A,dp,n,j,k,initialized,memLen);
                if (!currMaxSumFound || thisMaxSum>currMaxSum) { currMaxSum=thisMaxSum; currMaxSumFound=true; }
            }
        }
        answers[i]=currMaxSum;
        // vector<long long int> testVect; testVect.push_back(210); testVect.push_back(-12); testVect.push_back(410);
        // cout << arbitraryMax(testVect) << endl;
    }

    for(int i=0; i<t; i++) cout<<answers[i]<<endl;
}

vector<int> findAllAltIndex(int* A, int size, int index) {
    vector<int> indices;
    for(int i=index; i<size; i++) {
        if (A[index]>0 != A[i]>0) 
            indices.push_back(i);
    }
    return indices;
}

int calcLength(int* A, int* memLen, int index, int n) {
    vector<int> nextIndices=findAllAltIndex(A,n,index);
    if (nextIndices.empty()) memLen[index]=1; // no next alternating element is found
    else if (memLen[index]!=0) return memLen[index]; // memoization already initialized
    // 1 + solution to subproblem. assuming a subproblem still exists
    else memLen[index]=1+calcLength(A, memLen, nextIndices.front(), n);
    // cout<<"NEXT ALT INDEX: "<<nextIndex<<endl;
    // for (int ii=0; ii<n; ii++) cout << memLen[ii] << " "; cout<<endl;
    return memLen[index];

}

long long int solve(int* A, long long int** dp, int n, int index, int k, bool** initialized, int* memLen) {
    if (k==0) {
        dp[index][k]=0;
        // initialized[index][k]=true;
         return 0;
    }
    else if(initialized[index][k]) return dp[index][k];
    else {
        // cout <<"RECURRED: K=" <<k << endl; 
        try {
            vector<long long int> prevValues;
            for(int i=index; i<n; i++) {
                if (((A[index]>0) != (A[i]>0)) && (memLen[i]==k-1)) {
                    // cout <<"PRE-RECURRENCE MESSAGE: K=" <<k << endl; 
                    prevValues.push_back(solve(A, dp, n, i, k-1, initialized, memLen));
                }
            }
            // cout <<"PRE-SETTING DP MESSAGE: K=" <<k << endl; 
            dp[index][k] = A[index] + arbitraryMax(prevValues);
            // cout <<"PRE-SETTING INITIALIZED MESSAGE: K=" <<k << endl; 
            initialized[index][k]=true;
            return dp[index][k];
        } catch( const std::exception & ex ) {
            cerr << ex.what() << endl;
            throw;
        }
    }
}

long long int arbitraryMax(vector<long long int> nums) {
    if (nums.empty()) return 0;
    long long int max = *nums.begin();
    for(auto it:nums){
        if(it > max) max = it;
    }
    return max;
}


