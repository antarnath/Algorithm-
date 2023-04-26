#include<bits/stdc++.h>
using namespace std;

const int N=2e5+7;
vector<int>adj_list[N];
int visited[N];
int level[N];

void dfs(int node){
    visited[node] = 1;
    
    for(int adj_node : adj_list[node]){
        if(!visited[adj_node]){
            level[adj_node] = level[node] + 1;
            dfs(adj_node);
        }
    }
}


int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>> u>>v;
        adj_list[u].push_back(v);
    }

    int src;
    cin>>src;
    level[src] = 0;
    
    dfs(src);

    for(int i=1;i<=n;i++){
        cout<<"Node: "<<i<<", Level: "<<level[i]<<endl;
    }
}