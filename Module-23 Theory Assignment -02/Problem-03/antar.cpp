#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;
ll n, x, dp[N], cnt[N];

ll solve(){
    cin >> n;
    ll max_val = -1;
    for(int i = 1; i <= n; i++){
        cin >> x;
        cnt[x] ++;
        max_val = max(max_val, x);
    }
    dp[0] = 0;
    dp[1] = cnt[1];

    for(int i = 2; i <= max_val; i++){
        dp[i] = max(dp[i-1], dp[i-2] + cnt[i] * i);
    }

    cout<<dp[max_val];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}   