#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9+7;
vector<pair<int, int>> adj_list[N];
int visited[N], distances[N];
int n, m, q;

void dijkstra(int src){
    for(int i=1; i<=n; i++){
        distances[i] = INF;
        visited[i] = 0;
    }
    distances[src] = 0;

    for(int i=1; i<=n; i++){
        int node = -1;
        for(int j=1;j<=n;j++){
            if(visited[j] == 1) continue;
            if(node == -1 || distances[node] > distances[j]){
                node = j;
            }
        }
        
        visited[node] = 1;
        for(auto adj_entry : adj_list[node]){
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;
            if(distances[node] + edge_cst < distances[adj_node]){
                distances[adj_node] = distances[node] + edge_cst;
            }

        }
    }
}


int main(){
    cin >> n >> m >> q;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    for(int i=0;i<q;i++){
        int a, b;
        cin>>a>>b;
        if(a>n || b>n) cout<<"-1"<<endl;
        else{
            dijkstra(a);
            cout<<distances[b]<<endl;
        }
    }

}