#include<bits/stdc++.h>
using namespace std;

const int N = 50;
int dp[N];

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        dp[i] = 1;
    }

    for(int i = n + 1; i <= k; i++){
        int ans = 0;
        for(int j = 1; j <= n; j++){
            ans += dp[i - j];
        }
        dp[i] = ans;
    }

    cout<<dp[k]<<endl;
    return 0;
}   