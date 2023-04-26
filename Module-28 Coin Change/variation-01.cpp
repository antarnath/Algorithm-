/* 
Can't take a coin more than once, can we make the target
 */

#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &v, vector<vector<int>> &dp, int target, int n){
    if(target == 0){
        return true;
    }
    if(n == 0) return v[n] == target;
    if(dp[n][target] != -1) return dp[n][target];

    bool ans1 = solve(v, dp, target, n-1);
    if(target < v[n]){
        dp[n][target] = ans1;
        return ans1;
    }
    bool ans2 = solve(v, dp, target-v[n], n-1);
    dp[n][target] = (ans1 or ans2);
    return dp[n][target];
}


int main(){
    int n, target; cin >> n >> target;
    vector<int > v(n);
    vector<vector<int> > dp(n+1, vector<int> (target+1, -1));

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    bool check = solve(v, dp, target, n-1);
    if(check) cout << "target is exit" << endl;
    else cout << "target not exit" << endl;
}