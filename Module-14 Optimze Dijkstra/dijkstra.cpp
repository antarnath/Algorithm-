#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

vector< pair<int, int> > adj_list[N];
int visited[N], parent[N];
long long d[N];
int nodes, edges;

void dijkstra(int src){
    for(int i=1; i<=nodes; i++){
        d[i] = INF;
    }
    d[src] = 0;

    priority_queue< pair<long long, int> > pq;
    pq.push({0, src});

    while(!pq.empty()){
        pair<long long, int> head = pq.top();
        pq.pop();

        int seleted_node = head.second;

        if(visited[seleted_node]) continue;

        visited[seleted_node] = 1;

        for(auto adj_entry : adj_list[seleted_node]){
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;

            if(d[seleted_node] + edge_cst < d[adj_node]){
                d[adj_node] = d[seleted_node] + edge_cst;
                parent[adj_node] = seleted_node;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }

    // for(int i=0; i<nodes; i++){
    //     int seleted_node = -1;
    //     for(int j=1; j<=nodes; j++){
    //         if(visited[j]) continue;
    //         if(seleted_node==-1 || d[seleted_node] > d[j]){
    //             seleted_node = j;
    //         }
    //     }
        
    //     visited[seleted_node] = 1;

    //     for(auto adj_entry : adj_list[seleted_node]){
    //         int adj_node = adj_entry.first;
    //         int edge_cst = adj_entry.second;

    //         if(d[seleted_node] + edge_cst < d[adj_node]){
    //             d[adj_node] = d[seleted_node] + edge_cst;
    //         }
    //     }
    // }
}



int main(){
    cin >> nodes >> edges;
    for(int i=0; i<edges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;

    dijkstra(1);

    if(visited[nodes]==0){
        cout<<"-1"<<endl;
        return 0;
    }

    // for(int i=1; i<=nodes; i++){
    //     cout<<d[i]<<" ";
    // }
    int current_node = nodes;
    vector<int>path;

    while(true){
        path.push_back(current_node);
        if(current_node == src){
            break;
        }
        current_node = parent[current_node];
    }

    reverse(path.begin(), path.end());

    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }

    return 0;
}

/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1 
*/