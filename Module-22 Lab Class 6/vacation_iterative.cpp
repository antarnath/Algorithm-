#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int dp[N][4], days[N][4];

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            cin>>days[i][j];
        }
    }

    for(int i=1; i<=3; i++){
        dp[1][i] = days[1][i];
    }

    for(int i=2; i<=n; i++){
        for(int j=1; j<=3; j++){
            int max_profit = -1;
            for(int k=1; k<=3; k++){
                if(j==k) continue;
                int current_profit = dp[i-1][k] + days[i][j];
                max_profit = max(max_profit, current_profit);
            }
            dp[i][j] = max_profit;
        }
    }

    cout<<max({dp[n][1], dp[n][2], dp[n][3]})<<endl;

    return 0;
}