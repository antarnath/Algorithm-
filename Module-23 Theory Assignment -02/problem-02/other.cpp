#include<bits/stdc++.h>
using namespace std;
 
int dp[1001][1001], h[1001], n, k, t;
 
int main()
{   
    cin >> t;
    for(int tc = 1; tc <= t; tc++){ 
        cin>>n>>k;

        for(int i=0;i<n;i++)
            cin>>h[i];

        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for(int i = 0; i <= k; i++) 
            dp[0][i] = 0;

        for(int j = h[0]; j <= k; j++) 
            dp[1][j] = h[0];
    
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= k; j++){
                if(h[i-1]<=j)
                    dp[i][j]=max(dp[i-1][j], h[i-1] + dp[i-2][j-h[i-1]]);
                else
                    dp[i][j]=dp[i-1][j];          
            }
        }
        cout<<"Scenario #"<<tc<<": "<<dp[n][k]<<endl;
    }
    return 0;
}