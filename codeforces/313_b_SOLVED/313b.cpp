#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s; cin>>s; // read in input string
    int intStrLen=s.length();
    int m; cin>>m; // number of queries to handle
    int* answers=(int*)malloc(m*sizeof(int));

    int* dp=(int*)malloc(intStrLen*sizeof(int));
    // dp[i] is the number of ints that satisfies the condition up to and 
    // including the i-th character in the string
    for(int i=0; i<intStrLen-1; i++){
        if(i==0) (s[i]==s[i+1])?dp[i]=1:dp[i]=0;
        else if (s[i]==s[i+1]) dp[i]=dp[i-1]+1;
        else dp[i]=dp[i-1];
    }
    dp[intStrLen-1]=dp[intStrLen-2];

    for (int i=0; i<m; i++) {
        int l; cin>>l; l--;// the left bound (inclusive) of the query
        int r; cin>>r; r-=2;// the right bound (exclusive) of the query
        int count=0;
        (s[l]==s[l+1])?answers[i]=dp[r]-dp[l]+1:answers[i]=dp[r]-dp[l];
    }
    for (int i=0; i<m; i++) {
        cout<<answers[i]<<endl;
    }

}