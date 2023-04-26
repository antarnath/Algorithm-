#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

vector< pair<int, int> > adj_list[N];
int visited[N];
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
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}


int main(){
    cin >> nodes >> edges;
    for(int i=0; i<edges; i++){
        char a, b;
        int w;
        cin>>a;
        cin.ignore();
        cin>>b;
        cin.ignore();
        cin>>w;
        int u = a-'A'+1;
        int v = b-'A'+1;
        // cout<<u<<v<<endl;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 2;

    dijkstra(src);

  

    for(int i=1;i<=nodes;i++){
        char ch = 'A' + i - 1;
        cout<<"B to "<<ch<<" -> "<<d[i]<<" "<<endl;
    }
    cout<<endl;
    return 0;
}