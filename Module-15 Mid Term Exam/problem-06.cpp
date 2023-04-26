#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<int>adj_list[N];
int cat[N], arr[N];
int visited[N];
int cnt = 0;
int n, m;

void dfs(int head){
    visited[head] = 1;

    for(auto adj_node : adj_list[head]){
        if(visited[adj_node]==1){
            continue;
        }

        if(arr[adj_node]==1){
            cat[adj_node] = cat[head] + 1;
        }

        if(cat[adj_node] > m){
            continue;
        }

        if(adj_list[adj_node].size()==1){
            cnt++;
        }

        dfs(adj_node);
    }
}

int main(){
    cin>>n>>m;

    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1; i<n;i++){
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        
    }


    cat[1] = arr[1];
    dfs(1);

    cout<<cnt<<endl;


    return 0;
}