#include<bits/stdc++.h>
using namespace std;

const int N = 3000;
const long long INF = 1e18;
vector< pair<int, int> > adj_list[N];
int parent[N], n, m, last_update_node = -1;
long long d[N];
bool negative_cycle = false;

void bellman_ford(int src){
    for(int i=1; i<=n; i++){
        d[i] = INF;
    }

    d[src] = 0;

    for(int i=1; i<=n+1; i++){
        for(int node=1; node<=n; node++){
            for(auto adj_node : adj_list[node]){
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if(d[u] + w < d[v]){
                    d[v] = d[u] + w;
                    parent[v] = u;
                    if(i==n){
                        negative_cycle = true;
                        last_update_node = v;
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v, w});
    }

    bellman_ford(1);

    if(negative_cycle){
        cout<<"YES"<<endl;
        int selected_node = last_update_node;
        for(int i=1 ;i<n; i++){
            selected_node = parent[selected_node];
        }

        int des = selected_node;

        vector<int> path;

        while(true){
            path.push_back(selected_node);
            selected_node = parent[selected_node];
            if(selected_node == des) break;
        }
        path.push_back(selected_node);

        reverse(path.begin(), path.end());

        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }

    }
    else{
        cout<<"NO"<<endl;
    }


}