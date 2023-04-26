#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int> adj_list[N];
int visited[N];

bool dfs(int node, int parent){
    visited[node] = 1;

    for(int adj_node : adj_list[node]){
        if(!visited[adj_node]){
            bool got_cycle = dfs(adj_node, node);
            if(got_cycle) return true;
        }
        else if(visited[adj_node]==1 && adj_node != parent){
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    bool check = false;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(dfs(i, -1)){
                check = true;
                break;
            }
        }
    }

    if(check){
        cout<<"Cycle is pound"<<endl;
    }
    else{
        cout<<"Cycle is not pound"<<endl;
    }

    return 0;
}