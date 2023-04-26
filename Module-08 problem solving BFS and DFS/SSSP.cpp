#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int visited[N];
vector<int> adj_list[N];
int level[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = 1;

    level[src] = 0;

    while(!q.empty()){
        int head = q.front();
        q.pop();

        for(int adj_node : adj_list[head]){
            if(!visited[adj_node]){
                visited[adj_node] = 1;
                q.push(adj_node);
                level[adj_node] = level[head] + 1;

            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 0;
    bfs(src);

    for(int i=0;i<n;i++){
        cout<<"Node: "<<i<<", Level: "<<level[i]<<endl;
    }

    return 0;
}

