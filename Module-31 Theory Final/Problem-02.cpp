#include<bits/stdc++.h>
using namespace std;


const int N = 1001;
int visited[N][N], level[N][N];
int dx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dy[] = {-1, 1, -1, 1, -2, -2, 2, 2};

bool is_safe(pair<int, int> p){
    if(p.first >= 0 and p.first < 8 and p.second >= 0 and p.second < 8) return true;
    return false;
}

void bfs(pair<int,int> src, pair<int, int> des){
    visited[src.first][src.second] = 1;
    queue<pair<int,int> > q;
    q.push(src);

    while(!q.empty()){
        pair<int, int> head = q.front();
        if(head.first == des.first and head.second == des.second) return;
        q.pop();

        for(int i = 0; i < 8; i++){
            int new_x = head.first + dx[i];
            int new_y = head.second + dy[i];
            if(is_safe({new_x, new_y}) and !visited[new_x][new_y]){
                q.push({new_x, new_y});
                level[new_x][new_y] = level[head.first][head.second] + 1;
                visited[new_x][new_y] = 1;
            }
        }
    }
}

int main(){
    pair<int,int> src = {0, 0}, des = {5, 5};

    level[src.first][src.second] = 0;

    bfs(src, des);

    cout << level[des.first][des.second] << endl;
    
}