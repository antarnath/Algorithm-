#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 101, M = 1e5+7;
ll dp[N][M], wt[N], val[N], n, w;


ll solve(ll n, ll w){
    if(n == 0) return 0;

    if(dp[n][w]!= -1) return dp[n][w];

    if(w < wt[n]){
        dp[n][w] = solve(n-1, w);
        return dp[n][w];
    }

    dp[n][w] = max(val[n] + solve(n - 1, w - wt[n]), solve(n - 1, w));
    return dp[n][w];
}   

int main(){
    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        cin >> wt[i] >> val[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(n, w) << endl;
}