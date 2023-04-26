/* 
Can take a coin any number of times, in how many ways can we make the target
 */

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& coin, vector<vector<int> >&dp, int n, int target){
    if(target == 0) return 1;
    if(n == 0){
        if(target % coin[n] == 0) return 1;
        // if(coin[n] == target) return 1;

        return 0;
    }

    if(dp[n][target] != -1) return dp[n][target];

    int ans2 = 0;
    int val = target / coin[n];
    for(int i = 0; i <= val; i++){
        ans2 += solve(coin, dp, n-1, target-(i*coin[n]));
    }

    dp[n][target] =  ans2;
    return dp[n][target];

}


int main(){
    int n, target;
    cin >> n >> target;
    vector<int> coin(n);
    for(int i = 0; i < n; i++) cin >> coin[i];

    vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

    cout << solve(coin, dp, n-1, target);
}