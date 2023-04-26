/* 
Find the Length of the Longest Common Subsequence between two strings
    solve to Memoization way
 */

#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b, vector<vector<int> >&dp, int i , int j){
    if(i == a.size() || j == b.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(a[i] == b[j]) return dp[i][j] = 1 + LCS(a, b, dp, i+1, j+1);
    return dp[i][j] = max(LCS(a, b, dp, i+1, j) , LCS(a, b, dp, i, j+1));
}

int main(){
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(1001, vector<int>(1001, -1));

    cout << LCS(a, b, dp, 0, 0);
}