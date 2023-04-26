#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;
ll n, x, dp[N], cnt[N];

ll solve(int n){
    if(n==0) return 0;
    if(n == 1) return cnt[1];

    if(dp[n] != -1) return dp[n];

    dp[n] = max(solve(n-1), solve(n-2) + cnt[n] * n);

    return dp[n];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    ll max_val = -1;
    for(int i = 1; i <= n; i++){
        cin >> x;
        cnt[x]++;
        max_val = max(x, max_val);
    }
    memset(dp, -1, sizeof(dp));
    cout<<solve(max_val)<<endl;


    return 0;
}   