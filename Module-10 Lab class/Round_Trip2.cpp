
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>adj_list[N];
vector<int>visited(N);

bool check = false;
int val = 0;
void dfs(int src, int cnt){

    visited[src] = 1;
    cnt++;

    for(auto i : adj_list[src]){
        if(visited[i]==0){
            dfs(i, cnt);
        }
        else if(visited[i]==1){
            val = cnt;
            check = true;
            return;
        }
        else{
            visited[i] = 2;
        }
    }
}






int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
    }

    int a = -1, b = -1;
    for(int i=1; i<=n; i++){
        val = 0;
        dfs(i, 0);
        if(check && b < val){
            b = val;
            a = i;
            check = false;
        }
    }

    if(a && b){
        cout<<b + 2<<endl;
        for(int i=0; i<n; i++){
            visited[i] = 0;
        }

    }

    

    
}