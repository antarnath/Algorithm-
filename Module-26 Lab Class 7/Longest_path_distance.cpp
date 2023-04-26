#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> parent_list[N];
int dp[N], root, target_node;


int solve(int root, int target_node){
    if(root == target_node) return 0;
    if(dp[target_node]!= -1) return dp[target_node];

    int ans = 0;
    for(auto parent : parent_list[target_node]){
        ans = max(ans, solve(root, parent)+1);
    }

    dp[target_node] = ans;

    return ans;
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        parent_list[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));
    cin >> root >> target_node;

    cout << solve(root, target_node) << endl;

}