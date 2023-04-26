#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 1e5;
ll dp[N], gold[N], ans, t, n;

ll collected(ll n){
    if(n == 0) return 0;
    if(n <= 2) return gold[n];

    if(dp[n] != -1) return dp[n];

    ans = max(collected(n-2), collected(n-3)) + gold[n];
    dp[n] = ans;
    return ans;
}

ll solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> gold[i];
    }
    memset(dp, -1, sizeof(dp));
    return max(collected(n), collected(n-1));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        ans = solve();
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }
    return 0;
}