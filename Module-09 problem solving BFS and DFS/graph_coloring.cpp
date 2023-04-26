#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 7;
vector<int>adj_list[N];
bool visited[N];
int color[N];

bool dfs(int node){
    visited[node] = 1;
    
    for(auto adj_node : adj_list[node]){
        if(!visited[adj_node]){
            if(color[node]==1)  color[adj_node] = 2;
            else    color[adj_node] = 1;
            
            bool is_bicolorable = dfs(adj_node);
            if(!is_bicolorable) return false;
        }
        else{
            for(auto i : adj_list[node]){
                if(color[node]==color[i]) return false;
            }
        }
    }
    return true;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool is_bicolorable = true;

    for(int i=1; i<=n; i++){
        if(!visited[i] ){
            color[i] = 1;
            bool ok = dfs(i);
            if(!ok){
                is_bicolorable = false;
                break;
            }
        }
    }

    if(is_bicolorable){
        for(int i=1; i<=n; i++){
            cout<<color[i]<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

   
}