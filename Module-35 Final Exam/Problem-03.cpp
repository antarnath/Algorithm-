#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int maze[N][N], visited[N][N];
int n, m;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

bool is_safe(int x, int y){
    if(x >= 0 and x < n and y >=0 and y < m) return true;
    return false;
}

void dfs(int a, int b){
    visited[a][b] = 1;
    // cout << i << " " << j << endl;

    for(int i = 0; i < 8; i++){
        int x = a + dx[i];
        int y = b + dy[i];
        if(is_safe(x, y) and visited[x][y] ==0 and maze[x][y] == 1){
            
            dfs(x, y);
        }
    }

}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '#') maze[i][j] = 1;
            else maze[i][j] = 0;
        }
    }
    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(maze[i][j] == 1 and visited[i][j] == 0){
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << endl;
}


