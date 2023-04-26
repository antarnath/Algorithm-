#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adj_list[N];
int level[N];
int visited[N];
int n, m;

void bfs(int src){
    visited[src] = 1;
    level[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto adj_node : adj_list[node]){
            if(!visited[adj_node]){
                visited[adj_node] = 1;
                level[adj_node] = level[node] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // bfs(1);
    queue<int> q;
    int k;
    cin>>k;
    int arr[k];
    for(int i=0;i<k;i++){
        cin>>arr[i];
        q.push(arr[i]);
        visited[arr[i]] = 1;
        level[arr[i]] = 0;
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto adj_node : adj_list[node]){
            if(!visited[adj_node]){
                visited[adj_node] = 1;
                level[adj_node] = level[node] + 1;
                q.push(adj_node);
            }
        }
    }



    int max_level = -1, index = -1;

    for(int i=n; i>=1 ; i--){
        if(level[i] >= max_level){
            max_level = level[i];
            index = i;
        }
    }



    cout<<max_level<<endl;
    cout<<index<<endl;
}