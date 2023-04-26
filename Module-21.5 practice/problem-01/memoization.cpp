#include<bits/stdc++.h>
using namespace std;

const int N = 101;
unsigned long long dp[N];

int tabo(int n){
    if(n <= 3) return 1;

    if(dp[n] != -1) return dp[n];

    long long ans = tabo(n-1) + tabo(n-2) + tabo(n-3);

    dp[n] = ans; 
    return ans;
}


int main(){
    
    while(true){
        int n;
        cin>>n;
        memset(dp, -1, sizeof(dp));
        cout<<tabo(n)<<endl;
    }

    return 0;
}