#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e5;
vector<int> adj_list[N];
int visited[N];
 
list<int>store;
int starting;
 
 
bool dfs(int node, int parent){
    visited[node] = 1;
    store.push_back(node);
 
    for(int adj_node : adj_list[node]){
        if(!visited[adj_node]){
            bool got_cycle = dfs(adj_node, node);
            if(got_cycle){
                return true;
            }
        }
        else if(visited[adj_node]==1 ){
            starting = adj_node;
            return true;
        }
    }
    store.pop_back();
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
    }
 
    vector<int>v;
    
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
        while(!store.empty()){
            if(store.front()==starting){
                break;
            }
            store.pop_front();
        }
        cout<<store.size() + 1<<endl;
        while(!store.empty()){
            cout<<store.front()<<" ";
            store.pop_front();
        }
        cout<<starting<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
 
    return 0;
}