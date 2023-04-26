#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;

ll dp[N][N], n, x;
ll banana[N][N];


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

    for(int i = 1; i <= n;i++){
        dp[1][i] = banana[1][i];
    }

    for(int i = 2; i <= 2*n-1; i++){
        for(int j = 1; j <= n; j++){
            ll ans = max(dp[i-1][j], dp[i-1][j-1]);
            dp[i][j] = ans + banana[i][j];
        }
    }

    return dp[2*n-1][n];
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