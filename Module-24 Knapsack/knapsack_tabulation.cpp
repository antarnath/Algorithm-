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
ll wt[N], val[N];
int n, w;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        cin >> wt[i] >> val[i];
    }

    //1. handle base case
    for(int i = 1; i <= w; i++){
        dp[0][i] = 0;
    }

    // 2. loop over the states
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= w; j++){
            if(j < wt[i]){
                dp[i][j] = dp[i-1][j];
            }
            else{  
                dp[i][j] = max(
                    val[i] + dp[i - 1][j - wt[i]], 
                    dp[i - 1][j]
                );
            }
        }
    }

    cout<<dp[n][w]<<endl;

    return 0;
}