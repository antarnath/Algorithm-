#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin>>n>>k;
    int h[n];
    int dp[n];
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    dp[1] = 0;

    for(int i=2;i<=n;i++){
        dp[i] = INT_MAX;

        for(int j=1;j<=k;j++){
            if(i-j <= 0) break;

            int ans = dp[i-j] + abs(h[i] - h[i-j]);
            dp[i] = min(dp[i], ans);
        }
    }
    cout<<dp[n]<<endl;
}