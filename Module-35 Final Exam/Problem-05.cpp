#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& v, vector<vector<int>> &dp, int i, int j, int n, int m){
    if(i == -1 or j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = v[i][j] + max(solve(v, dp, i-1, j, n, m), solve(v, dp, i, j+1, n, m));
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n,  vector<int>(m));
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    cout << solve(v, dp, n-1, 0, n, m) << endl;
}