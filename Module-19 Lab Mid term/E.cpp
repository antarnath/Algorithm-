#include<bits/stdc++.h>
using namespace std;

const int N = 100;
char maze[N][N];
pair<int, int> path[N][N];
int visited[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

bool is_maze(pair<int, int> coord){
    if(coord.first>=0 && coord.first < n &&
        coord.second>=0 && coord.second < n){
            return true;
    }
    return false;
}
 
bool is_safe(pair<int, int> coord){
    if(maze[coord.first][coord.second]=='.' || maze[coord.first][coord.second]=='@') return true;
    return false;
}

void bfs(pair<int, int> coord){
    visited[coord.first][coord.second] = 1;
    path[coord.first][coord.second] = {-1, -1};

    queue<pair<int, int> > q;
    q.push(coord);

    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int x = head.first + dx[i];
            int y = head.second + dy[i];

            if(is_maze({x, y}) && is_safe({x, y}) && !visited[x][y]){
                q.push({x, y});
                visited[x][y] = 1;
                path[x][y] = {head.first, head.second};
            }
        }
    }

}

int main(){
    cin>>n;
    pair<int, int> src, des;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='X'){
                src = {i, j};
            }
            if(maze[i][j]=='@'){
                des = {i, j};
            }
        }
    }

    bfs(src);

    if(visited[des.first][des.second]){
        cout<<"Y"<<endl;
        pair<int, int> old = des;
        while(true){
            if(des.first==src.first && des.second==src.second) break;
            maze[des.first][des.second] = '+';
            des = path[des.first][des.second];
        }
        maze[old.first][old.second] = '@';
        maze[src.first][src.second] = '+';

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<maze[i][j];
            }
            cout<<endl;
        }
    }
    else{
        cout<<"N"<<endl;
    }

    return 0;
    
}