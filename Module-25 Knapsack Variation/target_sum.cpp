#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    int solve(vector<int>&a, vector<vector<int>> &dp, int n, int target, int val){
        if(n == 0){
            if(target == val) return 1;
            return 0;
        }

        if(dp[n][val+1000] != -1) return dp[n][val+1000];

        int ans1 = solve(a, dp, n-1, target, val + a[n]);
        int ans2 = solve(a, dp, n-1, target, val - a[n]);
        int ans = ans1 + ans2;
        dp[n][val+1000] = ans;
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target){
        int n = nums.size();
        vector<int> a(n+2);
        for(int i = 0; i < n; i++){
            a[i+1] = nums[i];
        }
        vector<vector<int>>dp(n+2, vector<int> (2004, -1));
        return solve(a, dp, n, target, 0);
    }
};

int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    solution t;
    cout<<t.findTargetSumWays(nums, target);
}