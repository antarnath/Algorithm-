#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];
int d[N];


int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) d[i] = -1;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    int src = 1;
    d[src] = 0;
    bool positive_cycle = false;

    for(int i = 1; i <= n; i++){
        for(int node = 1; node <= n; node++){
            for(auto adj_entry : adj_list[node]){
                int u = node;
                int v = adj_entry.first;
                int w = adj_entry.second;
                if(d[u] + w > d[v]){
                    d[v] = d[u] + w;
                    if(i == n) positive_cycle = true;
                }
            }
        }
    }

    if(positive_cycle) cout << "Positive cycle found" << endl;
    else cout << "Positive cycle not found" << endl;
}