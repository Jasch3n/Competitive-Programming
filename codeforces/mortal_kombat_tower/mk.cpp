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
        //dp[i][self] is the min points needed to defeat first i bosses when the next move is your friend or yourself
        //self = 0 is self, 1 is friend    
        vector<array<int, 2>> dp(n + 1, {INF, INF});
        dp[0] = {INF, 0};

        for (int i = 0; i < n; i ++){      //for each boss
            for(int j = 0; j < 2; j ++){    //for each player
                for(int bossNum = 1; bossNum <= min(n - i, 2); bossNum ++){
                    //looking two levels deep at once
                    int hardBossCount = A[i] + (bossNum > 1 ? A[i + 1] : 0);
                    //a player either gives up session after one or two bosses
                    dp[i + bossNum][!j] = min(dp[i + bossNum][!j], dp[i][j] + (j==1 ? hardBossCount : 0));
                }
            }
        }

        answers.push_back(min(dp[n][0], dp[n][1]));
    }

    for(auto i: answers) cout << i << endl;
}