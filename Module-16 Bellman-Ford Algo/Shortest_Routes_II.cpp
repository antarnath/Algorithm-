#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int INF = 1e9 + 7;
vector<pair<int, int>> adj_list[N];
int d[N], n, m, q;

void bellman_ford(int src){
    d[src] = 0;
    for(int i = 1; i <= n-1; i++){
        for(int node = 1; node <= n; node++){
            for(auto adj_node : adj_list[node]){
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if(d[u] + w < d[v]){
                    d[v] = d[u] + w;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    for(int i = 0; i < q; i++){
        int a, b;
        for(int i = 0; i <= n; i++){
            d[i] = INF;
        }
        cin >> a >> b;

        bellman_ford(a);

        if(d[b] != INF) cout<<d[b]<<endl;
        else cout<<"-1"<<endl;
    }

    return 0;
}