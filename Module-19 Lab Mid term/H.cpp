#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
#define MAX 101

using namespace std;
int g[MAX][MAX], used[MAX], dist[MAX], cost[MAX], parent[MAX];

void Relax(int i, int j)
{
    if (dist[i] + g[i][j] < dist[j]) {
        dist[j] = dist[i] + g[i][j];
        parent[j] = i;
    }
}


int main() {
    int n, m;
    cin >> n;
    int s = 1, f = n;
    memset(g, 0x3F, sizeof(g));
    memset(used, 0, sizeof(used));
    memset(dist, 0x3F, sizeof(dist));
    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }

    cin >> m;

    int b,e;
    for (int i = 0; i < m; ++i) {
        cin >> b >> e;
        g[b][e] = cost[b];
        g[e][b] = cost[e];
    }

    dist[s] = 0;
    int min, v;

    for (int i = 1; i < n; i++)
    {
         min = INF; v = -1;
        for (int j = 1; j <= n; j++) {
            if (used[j] == 0 && dist[j] < min) {
                min = dist[j];
                v = j;
            }
        }
        if (v < 0) break;    
        for (int j = 1; j <= n; j++) {
            if (used[j] == 0 && g[v][j] != -1) {
                Relax(v, j);
            }
        }

        used[v] = 1;
    }

    if (dist[f] == INF) {
        cout << -1;
    }else {
        cout << dist[f] << endl;
    }


    return 0;
}