#include<bits/stdc++.h>
using namespace std;

const int N = 100;
long long dp[N];

int main(){
    int n;
    cin>>n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cout<<dp[n]<<endl;

    return 0;
}