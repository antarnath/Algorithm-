#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001], h[1001], n, k, t;


int solve(int n, int w){
    if(n < 1) return w;
    if(dp[n][w] != -1) return dp[n][w];

    if(h[n] + w <= k)
        dp[n][w] = max(solve(n-2, w+h[n]), solve(n-1, w));
    else
        dp[n][w] = solve(n-1, w);
    return dp[n][w];
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> h[i];
        }
        for(int i = 0; i <= 1001; i++) 
            dp[0][i] = 0;
            dp[i][]
        


        cout<<"Scenario #"<<tc<<": "<<solve(n, 0)<<endl;
    }
    return 0;
}