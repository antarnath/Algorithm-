#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int h[N], n, k;
int dp[N];

int stone(int n){
    if(n<=1) return 0;
    if(dp[n] != -1) return dp[n];
    
    int ans = INT_MAX;

    for(int i=1; i<=k; i++){
        if(n-i <= 0) break;
        ans = min(ans, abs(h[n-i] - h[n]) + stone(n-i));
    }

    dp[n] = ans;
    // cout<<"n->"<<ans<<endl;
    return ans;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    memset(dp, -1, sizeof(dp));

    cout<<stone(n)<<endl;

}