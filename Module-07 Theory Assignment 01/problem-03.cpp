#include<bits/stdc++.h>
using namespace std;

vector<bool> vis;
int n, m;
vector<vector<int>> adj;
vector<int> components;

void dfs(int start){
    vis[start] = true;
    for(auto ele : adj[start]){
        if(!vis[ele]){
            vis[ele] = true;
            dfs(ele);
        }
    }
}

int main(){
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}