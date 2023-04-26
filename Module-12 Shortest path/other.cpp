#include<bits/stdc++.h>
using namespace std;

const int N = 2e+5;
vector<int> adj_list[N];
int visitd[N], level[N], parent[N];
int n, m, u, v;


void dfs(int src){
    visitd[src] = 1;

    for(int adj_node : adj_list[src]){
        if(visitd[adj_node]==0){
            level[adj_node] = level[src] + 1;
            parent[adj_node] = src;
            dfs(adj_node);
            
        }
    }

}






int main(){
    cin>> n>> m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i=0; i<=n;i++){
        cout<<i<<" -> ";
        for(int j=0;j<adj_list[i].size();j++){
            cout<<adj_list[i][j]<<" ";
        }
        cout<<endl;
    }

}