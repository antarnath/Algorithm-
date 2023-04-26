#include<bits/stdc++.h>
using namespace std;
const int N = 101;
const int M = 1e5 + 5;
int nums[N];
int dp[N][M];

bool solve(int n, int target){
    if(n == 0){
        if(target == 0) return 1;
        return 0;
    }

    if(dp[n][target] != -1) return dp[n][target];

    int ans1 = solve(n - 1, target);
    if(target < nums[n]){
        dp[n][target] = ans1;
        return ans1;
    }
    int ans2 = solve(n - 1, target - nums[n]);
    int ans = ans1 or ans2;
    dp[n][target] = ans;
    return ans;
}

int main(){
    int n, w;
    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }

    // 1. handle base case
    dp[0][0] = 1;

    for(int i = 1; i <= w; i++){
        dp[0][i] = 0;
    }

    // 2. loop over the states
    for(int i = 1; i <= n; i++){
        for(int target = 1; target <= w; target++){
            // 2.1. calculate answer from smaller sub-problems
            int ans1 = dp[i - 1][target];
            if(target < nums[i]){
                dp[i][target] = ans1;
            }
            else{
                int ans2 = dp[i - 1][target - nums[i]];
                dp[i][target] = ans1 or ans2;
            }
        }
    }

    // cout<<dp[n][w]<<endl;

    for(int i = 1; i <= w; i++){
        cout<<dp[n][i]<<endl;
    }


    return 0;
}


/* 
5 11
4 9 3 23 13


8 9999
3 34 4 12 5 2 27 9
 */