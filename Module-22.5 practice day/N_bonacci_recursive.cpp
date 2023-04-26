#include<bits/stdc++.h>
using namespace std;

const int N = 50;
int dp[N];

int n_bonacci(int n, int k){
    if(k <= n) return 1;

    if(dp[k] != -1) return dp[k];

    int ans = 0;

    for(int i = 1; i <= n; i++){
        ans += n_bonacci(n, k - i);
    }

    dp[k] = ans;
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout<<n_bonacci(n, k)<<endl;

    return 0;
}