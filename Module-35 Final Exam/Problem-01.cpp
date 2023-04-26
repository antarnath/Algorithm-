#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<pair<int, int>> adj_list[N];
int adj_mat[N][N];
int nodes, edges;

void convert_matrix(){
    for(int i = 1; i <= nodes; i++){
        for(auto adj_entry : adj_list[i]){
            int u = i;
            int v = adj_entry.first;;
            int w = adj_entry.second;;
            adj_mat[u][v] = adj_mat[v][u] = w;
        }
    }
}

int main(){
    cin >> nodes >> edges;
    for(int i = 0; i < edges; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    convert_matrix();
    
    for(int i = 1; i <= nodes; i++){
        for(int j = 1; j <= nodes; j++){
            cout << adj_mat[i][j] << " ";
        } cout << '\n';
    }
}