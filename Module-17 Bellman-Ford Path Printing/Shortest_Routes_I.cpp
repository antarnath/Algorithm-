#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const long long INF = 1e18;
vector< pair<int, int> > adj_list[N];
long long d[N];
int n, m, visited[N];

// void bellman_ford(int src){
//     for(int i=1; i<=n; i++){
//         d[i] = INF;
//     }

//     d[src] = 0;

//     for(int i=1; i<n; i++){
//         for(int node=1; node<=n; node++){
//             for(auto adj_node : adj_list[node]){
//                 int u = node;
//                 int v = adj_node.first;
//                 int w = adj_node.second;

//                 if(d[u] + w < d[v]){
//                     d[v] = d[u] + w;
//                 }
//             }
//         }
//     }
// }

void dijkstra(int src){
    for(int i=1;i<=n;i++){
        d[i] = INF;
    }

    d[src] = 0;

    priority_queue< pair<long long, int> > pq;
    pq.push({0, src});

    while(!pq.empty()){
        pair<int, int> head = pq.top();
        pq.pop();

        int selected_node = head.second;
        if(visited[selected_node]) continue;
        visited[selected_node] = 1;

        for(auto adj_entry : adj_list[selected_node]){
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;

            if(d[selected_node] + edge_cst < d[adj_node]){
                d[adj_node] = d[selected_node] + edge_cst;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v, w});
    }

    // bellman_ford(1);

    dijkstra(1);

    for(int i=1; i<=n; i++){
        cout<<d[i]<<" ";
    }

    return 0;
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" -> ";
    //     for(int j=0;j<adj_list[i].size();j++){
    //         cout<<"("<<adj_list[i][j].first<<", "<<adj_list[i][j].second<<"), ";
    //     }
    //     cout<<endl;
    // }
}