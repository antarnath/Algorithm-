/* 
Can't take a coin more than once, in how many ways can we make the target
 */

#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

int16_t solve(vector<int> &v, vector<vector<int>> &dp, int target, int n){
    if(target == 0){
        return 1;
    }
    if(n == 0){
        if(v[n] == target) return 1;
        return 0;
    }
    if(dp[n][target] != -1) return dp[n][target];

    int ans1 = solve(v, dp, target, n-1);
    if(target < v[n]){
        dp[n][target] = ans1;
        return ans1;
    }
    int ans2 = solve(v, dp, target-v[n], n-1);
    dp[n][target] = (ans1 + ans2);
    return dp[n][target];
}


int main(){
    int n, target; cin >> n >> target;
    vector<int > v(n);
    vector<vector<int> > dp(n+1, vector<int> (target+1, -1));

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int cnt = solve(v, dp, target, n-1);

    cout << cnt << endl;
}