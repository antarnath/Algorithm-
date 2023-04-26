#include<bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 7;
long long h[N], dp[N];

int main(){
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    dp[1] = 0;
    dp[2] = abs(h[0] - h[1]);

    for(int i=2;i<=n;i++){
        long long ans1 = dp[i-1] + abs(h[i] - h[i-1]);
        if(i==2)
            dp[i] = ans1;
        else{
            long long ans2 = dp[i-2] + abs(h[i] - h[i-2]);
            dp[i] = min(ans1, ans2);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}