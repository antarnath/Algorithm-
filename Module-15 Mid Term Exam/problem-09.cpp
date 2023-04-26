/* 
PSEUDOCODE:
- declared vector for adjcency list
- visited array and parent array
- destance arry d
- parent_node and last_node declared two variable this node means first sortest path last node and this node parent

- two time called dijkstra function
- dijkstra function
    - 1 to nodes all node distance infinite
    - source node distance is 0
    - declared priority queue
    - source node distanc and source node pair push

    -while priority queue is empty
        - capture priority queue top and priority queue pop
        - check node is visited or not 
        - node not visited then visited
        - travers all adjency node
            -if node is equeal to parent_node and adjency node == last node
                -continue
            if d[node] + cst(node, adjency node) < d[adjency node]
                d[adjency node] = d[node] + cst(node, adjency node)
                parent[adjency node] = node
                priority queue push adjecny node



- main function 
    dijkstra funciton called two time

    first called dijkstra
        parent_node = shorest path last value parent
        last_node = shorst path last value
    
    second called dijkstra 
        when called second time dijkstra function then dijkstra funciton
            can not count first shorest path because when find frist dijkstra funciton
                last value and parent and match it than it is continue

 */






#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];
int visited[N], parent[N];

long long d[N];
int nodes, edges, parent_node=-1, des_node=-1;

void dijkstra(int src){
    for(int i=1;i<=nodes;i++){
        d[i] = INF;
    }

    d[src] = 0;

    priority_queue<pair<int, int> > pq;
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
            
            if(seleted_node==parent_node && adj_node == des_node){
                continue;
            }
            if(d[seleted_node] + edge_cst < d[adj_node]){
                d[adj_node] = d[seleted_node] + edge_cst;
                parent[adj_node] = seleted_node;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}


int main(){
    cin>>nodes >> edges;

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
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    char src, des;
    cin>>src;
    cin.ignore();
    cin>>des;
    cin.ignore();


// parent_node dijkstra function called
    dijkstra(src-'A'+1);
  

// Second Dijkstra function called
    parent_node = parent[des-'A'+1];
    des_node = des - 'A' + 1;

    for(int i=0;i<=nodes;i++){
        parent[i] = 0;
        d[i] = INF;
        visited[i] = 0;
    }

    dijkstra(src-'A'+1);


    int a= src - 'A' + 1, b = des - 'A' + 1;
    vector<char> v;

    while(true){
        v.push_back(b);
        if(b==a) break;

        b = parent[b];

    }

    reverse(v.begin(), v.end());

    for(int i=0;i<v.size();i++){
        char ch = v[i] + 'A' -1;
        cout<<ch<<" ";
    }
    
}