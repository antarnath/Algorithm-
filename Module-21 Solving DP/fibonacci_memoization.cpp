#include<bits/stdc++.h>
using namespace std;

const int N = 100;

int dp[N];

int fib(int n){
    // 1. base case
    if(n <= 2) return 1;

    // 2. check if current state is already solved, return the result
    if(dp[n] != -1) return dp[n];

    // 3. calculate from smaller sub-problems
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}


int main(){
    int n;
    cin>>n;

    memset(dp, -1, sizeof(dp));

    cout<<fib(n)<<endl;
}