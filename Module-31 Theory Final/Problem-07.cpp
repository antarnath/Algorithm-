

/* 

Memoizatoin

int brute(int id){
    if(id >= n) return 0;
    if(dp[id] != -1) return dp[id];

    int ans = max({1 + brute(id + 1), 2 + brute(id + 3), 3 + brute(id + 5});
    dp[id] = ans;
    return dp[id];
}


Tabulation:


 */


#include<bits/stdc++.h>
using namespace std;

int dp[100];
int n;



int main(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int ans1 = 0, ans2 = 0, ans3 = 0;
        if(i - 1 < 0) ans1 = 1;
        else ans1 = 1 + dp[i - 1];

        if(i - 3 < 0) ans2 = 2;
        else ans2 = 2 + dp[i - 3];

        if(i - 5 < 0) ans3 = 3;
        else ans3 = 3 + dp[i - 5];

        dp[i] = max({ans1, ans2, ans3});
    }
    cout << dp[n] << endl;

}