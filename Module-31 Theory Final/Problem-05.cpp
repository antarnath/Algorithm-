#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
bool visited[N];

void dfs(int src){
    char c = (char)(src - 1 + 'A');
    cout << c << " ";
    visited[src] = true;

    for(auto adj_node : adj_list[src]){
        if(!visited[adj_node]) dfs(adj_node);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        char a, b;
        cin >> a >> b;
        int u = (int)(a-'A' + 1);
        int v = (int)(b-'A' + 1);
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 3;

    dfs(src);


}