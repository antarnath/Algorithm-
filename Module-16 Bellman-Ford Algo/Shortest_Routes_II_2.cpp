#include<bits/stdc++.h>
using namespace std;


const int N = 1000;
const long long INF = 1e18;
vector< pair<int, int> > adj_list[N];
int n, m, q, visited[N];
long long d[N];

void dijkstra(int src){
    for(int i=1;i<=n;i++){
        d[i] = INF;
        visited[i] = 0;
    }

    d[src] = 0;

    priority_queue< pair< int, int> > pq;
    pq.push({0, src});

    while(!pq.empty()){
        pair<int, int> head = pq.top();
        pq.pop();

        int seleted_node = head.second;

        if(visited[seleted_node]) continue;

        visited[seleted_node] = 1;

        for(auto adj_entry : adj_list[seleted_node]){
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;

            if(d[seleted_node] + edge_cst < d[adj_node]){
                d[adj_node] = d[seleted_node] + edge_cst;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }

}

int main(){
    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;

        dijkstra(a);

        if(d[b] != INF) cout<<d[b]<<endl;
        else cout<<"-1"<<endl;
    }

    return 0;
}