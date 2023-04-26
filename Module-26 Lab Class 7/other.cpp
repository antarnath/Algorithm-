#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int> > dp){
    int n = dp.size();
    cout<<n<<endl;
    cout<<dp[0].size()<<endl;
}


int main(){
    vector<vector<int> > dp(3, vector<int> (4));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cin >> dp[i][j];
        }
    }

    solve(dp);
}