#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
 
 
int main(){
    int t;
    cin >> t;
    for(int j = 1; j <= t; j++){
        int n;
        cin>>n;
        long long arr[N];
        long long dp[N];
        for(int i = 1; i <= n; i++){
            cin>>arr[i];
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        dp[1] = arr[1];
        dp[2] = arr[2];
        for(int i = 3; i <= n; i++){
            dp[i] = max(dp[i-2], dp[i-3]) + arr[i];
        }
        cout<<"Case "<<j<<": "<<max(dp[n], dp[n-1])<<endl;
    }
 
    return 0;
}