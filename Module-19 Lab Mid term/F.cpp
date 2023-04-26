#include<bits/stdc++.h>
using namespace std;

const int N = 101;
vector<int> adj_list[N];
vector< pair<int, int> > all_edge;
set<pair<int, int> > remove_edge;
int visited[N];

void dfs(int src, int parent){
    visited[src] = 1;

    for(auto adj_node : adj_list[src]){
        if(!visited[adj_node]){
            dfs(adj_node, src);
        }
        else if(adj_node != parent){
            remove_edge.insert({adj_node, src});
            remove_edge.insert({src, adj_node});
        }
    }
}


int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m;i++){
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        all_edge.push_back({u, v});
    }

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" -> ";
    //     for(int j=0;j<adj_list[i].size();j++){
    //         cout<<adj_list[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    dfs(1, -1);

    for(auto edge : all_edge){
        int u = edge.first;
        int v = edge.second;
        if(!remove_edge.count({u, v})){
            cout<<u<<" "<<v<<endl;
        }
    }

    return 0;
}