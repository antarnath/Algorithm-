#include<bits/stdc++.h>
using namespace std;

const long long N = 10^5 + 7;
long long h[N], dp[N];

int stone(int n){
    if(n <= 1) return 0;

    if(dp[n] != -1) return dp[n];

    long long ans1 = stone(n-1) + abs(h[n] - h[n-1]) ;
    
    if(n==2){
        dp[n] = ans1;
        return ans1;
    }

    long long ans2 = stone(n-2) + abs(h[n] - h[n-2]) ;
    long long ans = min(ans1, ans2);
    
    dp[n] = ans;
    return ans;
}


int main(){
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    // memset(dp, -1, sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i] = -1;
    }

    cout<<stone(n);
}