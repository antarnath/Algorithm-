#include<bits/stdc++.h>
using namespace std;

const int N = 100000007;

int solve(vector<int>&a, vector<int>&b, vector<vector<int> >&dp, int i,int n, int target){
    if(target == 0) return 1;
    if(i == n) return 0;

    if(dp[i][target] != -1) return dp[i][target];

    int ans = 0;
    for(int j = 0; j <= b[i] and target - j*a[i] >= 0; j++){
        ans += (solve(a, b, dp, i+1, n, target - j*a[i])) % N;
    }

    dp[i][target] = ans % N;
    return dp[i][target];
}

void testCase(int ok){
    int n, k;
    cin >> n >> k;
    vector<int > a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<vector<int> >dp(n+1, vector<int>(k+1, -1));
    cout << "Case "<<ok <<": ";
    cout << solve(a, b, dp, 0, n, k) << endl;


}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        testCase(i);
    }

    return 0;
}

