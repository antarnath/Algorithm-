#include<bits/stdc++.h>
using namespace std;
vector<bool>vis;
vector<vector<int>> adj;
int n, m;

void dfs(int s){
    stack<int> st;

    st.push(s);
    vis[s] = true;

    while(!st.empty()){
        int val = st.top();
        st.pop();

        if(!vis[val])
            cout<<val<<" ";
        

        for(int i=0;i<adj[val].size();i++){
            if(!vis[adj[val][i]]){
                st.push(adj[val][i]);
                vis[adj[val][i]] = true;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    vis = vector<bool>(n);
    adj = vector<vector<int>>(n);

    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
}