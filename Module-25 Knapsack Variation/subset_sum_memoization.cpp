#include<bits/stdc++.h>
using namespace std;
const int N = 101;
const int M = 1e5 + 5;
int nums[N];
int dp[N][M];

bool solve(int n, int target){
    if(n == 0){
        if(target == 0) return 1;
        return 0;
    }

    if(dp[n][target] != -1) return dp[n][target];

    int ans1 = solve(n - 1, target);
    if(target < nums[n]){
        dp[n][target] = ans1;
        return ans1;
    }
    int ans2 = solve(n - 1, target - nums[n]);
    int ans = ans1 or ans2;
    dp[n][target] = ans;
    return ans;
}

int main(){
    int n, target;
    cin >> n >> target;
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }

    
    memset(dp, -1, sizeof(dp));
    cout<<solve(n, target)<<endl;

    return 0;
}


/* 

8 9999
3 34 4 12 5 2 27 9
 */