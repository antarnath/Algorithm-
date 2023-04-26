#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<pair<int, int> > adj_list[N];
int visited[N];

int max_score = INT_MIN, n, m;

bool detect_cycle(int node){
    visited[node] = 1;

    for(auto adj_node : adj_list[node]){
        if(visited[adj_node.first]==0){
            bool got_cycle = detect_cycle(adj_node.first);
            if(got_cycle){ 
                return true;
            }
        }
        else if(visited[adj_node.first] == 1){
            return true;
        }
    }

    visited[node] = 2;
    return false;
}

void dfs(int src, int &score){

    if(src == n) max_score = max(max_score, score);

    for(auto adj_entry : adj_list[src]){
        int adj_node = adj_entry.first;
        int edge_cst = adj_entry.second;

        score += edge_cst;
        dfs(adj_node, score);
        score -= edge_cst;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v, w});
    }

    int a = 0;

    if(detect_cycle(1)){
        cout<<"-1"<<endl;
        return 0;
    }
    dfs(1, a);



    cout<<max_score<<endl;

    return 0;
}