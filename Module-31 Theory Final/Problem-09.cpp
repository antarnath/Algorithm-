#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
int dp[N][N];
int val[N], wt[N];

int solve(int n, int target){
    if(n == 0) return 0;

    if(dp[n][target] != -1) return dp[n][target];

    if(target < wt[n]) return dp[n][target] = solve(n-1, target);
    return dp[n][target] = max(solve(n-1, target-wt[n]), solve(n-1, target));
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        float x;
        cin >> x >> val[i];
        wt[i] = x * 100;
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(n, 100) << endl; 
}