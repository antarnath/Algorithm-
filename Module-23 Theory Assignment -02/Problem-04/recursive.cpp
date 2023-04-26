#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
ll dp[N][N], n, x;
ll banana[N][N];

ll count_banana(ll n, ll k){
    if(n < 1 || k < 1) return 0;
    if(banana[n][k] == 0) return 0;
    if(n == 1) return banana[n][k];

    if(dp[n][k] != -1) return dp[n][k];

    ll ans = max(count_banana(n-1, k), count_banana(n-1, k-1)) + banana[n][k];
    dp[n][k] = ans;
    return dp[n][k];
}


ll solve(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    memset(banana, 0, sizeof(banana));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin>>x;
            banana[i][j] = x;
        }
    }
    int k = 2;
    for(int i = n + 1; i < 2*n; i++){
        for(int j = k; j <= n; j++){
            cin>> x;
            banana[i][j] = x;
        }
        k++;
    }

    return count_banana(2*n-1, n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    for(int tc = 1; tc <= t; tc++){
        cout<< "Case "<< tc <<": "<<solve()<<endl;
    }
    return 0;
}
