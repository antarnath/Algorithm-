#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
const int INF = 1e9;
int d[N][N];
int n, m;


int main(){
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            d[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
    }

    for(int i=1; i<=n; i++){
        d[i][i] = 0;
    }

    for(int k = 1; k <= n ; k++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }
}