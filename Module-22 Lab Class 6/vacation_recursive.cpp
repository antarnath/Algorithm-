#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
long long dp[N][4];
int days[N][4];

long long solve(int n, int i){
    if(n < 1) return 0;

    if(dp[n][i] != -1) return dp[n][i];

    long long ans = -1;
    for(int j=1; j<=3; j++){
        if(i==j) continue;
        long long val = days[n][i] + solve(n-1, j);
        ans = max(val, ans);
    }

    dp[n][i] = ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>days[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    long long ans = -1;
    for(int i=1;i<=3;i++){
        ans = max(solve(n, i), ans);
    }

    cout<<ans<<endl;

    return 0;
}