#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;


int main(){
    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    bool check = true;

    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(adj[i][j] != adj[j][i]){
                check = false;
                break;
            }
        }
    }

    if(check) cout<<"Bi-directional";
    else cout<<"Not Bi-directional";

    return 0;
}