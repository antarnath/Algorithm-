/* 
Find the Length of the Longest Common Subsequence between two strings
    solve to tabulation way
 */


#include<bits/stdc++.h>
using namespace std;


int main(){
    string a, b;
    cin >> a >> b;

    vector<vector<int> > dp(1001, vector<int>(1001, 0));

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout << dp[a.size()][b.size()] << endl;
}