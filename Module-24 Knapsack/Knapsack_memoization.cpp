/* 

    1. state : knapsack(n, cap) -> maximum profit considering objects 1 to n and capacity = cap
    2. recurrance:
        knapsack(n, cap) -> max {
                            val[n] + knapsack(n-1, cap - wt[n]),
                            knapsack(n-1, cap)
                        }
    3. base_case: knapsack(0, x) = 0
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 101;
ll dp[N][N];
int wt[N], val[N];
int n, w;

ll knapsack(int n, int w){
    if(n==0) return 0;

    if(dp[n][w] != -1) return dp[n][w];

    if(w < wt[n]){
        ll ans = knapsack(n-1, w);
        dp[n][w] = ans;
        return dp[n][w];
    }

    ll ans1 = val[n] + knapsack(n-1, w - wt[n]);
    ll ans2 = knapsack(n-1, w);

    dp[n][w] = max(ans1, ans2);
    return dp[n][w];    
}

void solve(){
    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        cin >> wt[i] >> val[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<knapsack(n, w)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}