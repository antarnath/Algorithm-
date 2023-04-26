#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;
vector<pair<int, int>> adj_list[N];
int visited[N];
long long d[N];

void Dijkstra(int src){
    for(int i = 1; i <= N; i++) d[i] = INF;
    d[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while(!pq.empty()){
        pair<long long, int> head = pq.top();
        pq.pop();

        int select_node = head.second;
        if(visited[select_node]) continue;

        visited[select_node] = true;

        for(auto edge_entry : adj_list[select_node]){
            int adj_node = edge_entry.first;
            int edge_cst = edge_entry.second;
            
            if(d[select_node] + edge_cst < d[adj_node]){
                d[adj_node] = d[select_node] + edge_cst;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}


int main(){
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i = 0; i < edges; i++){
        char a, b;
        int w;
        cin >> a >> b >> w;
        int u = (int)(a-'A'+1);
        int v = (int)(b-'A'+1);
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 2;

    Dijkstra(src);

    for(int i = 1; i <= nodes; i++){
        cout << d[i] << " ";
    }
}