#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<int> adj_list[N];
vector<int>visited(N);


void dfs(int node){
    visited[node] = 1;
    for(int adj_node : adj_list[node]){
        if(visited[adj_node]==0){
            dfs(adj_node);
        }
    }
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
    
    vector<int>ans;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            ans.push_back(i);
        }
    }

    if(ans.size() <= 1){
        cout<<"0"<<endl;
    }
    else{
        cout<<ans.size()-1<<endl;
        for(int i=1; i<=ans.size()-1; i++){
            cout<<ans[i]-1<<" "<<ans[i]<<endl;
        }
    }

    return 0;
}