/* 

5 8
########
#..#...#
####.#.#
#..#...#
########

output:
    3

(x, y) --> right -->(x, y+1);
       --> left  -->(x, y-1);
       --> up    -->(x-1, y);
       --> down  -->(x+1, y);

dx[] = {0, 0, -1, 1}
dy[] = {1, -1, 0, 0}

*/

#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N = 1005;
int maze[N][N];
int visited[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int , int> coord){
    if((coord.first>=0 && coord.first<n)&&
        (coord.second>=0 && coord.second<m)){
            return true;
    }
    return false;
}

bool is_safe(pair<int , int> coord){
    if(maze[coord.first][coord.second] == 0) return true;
    return false;
}


void bfs(pair< int, int > p){
    queue< pair<int , int> > q;
    q.push(p);
    visited[p.first][p.second] = 1;

    while(!q.empty()){
        pair<int , int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;
        for(int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            pair<int, int> adj_node = {new_x, new_y};

            if(is_inside(adj_node) && is_safe(adj_node) && !visited[adj_node.first][adj_node.second]){
                q.push(adj_node);
                visited[adj_node.first][adj_node.second] = 1;
            }
        }
    }
}

pair<int, int> is_unvisited(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!maze[i][j] && !visited[i][j]){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string input;
        cin>>input;
        for(int j=0; j<m; j++){
            if(input[j]=='#'){
                maze[i][j] = -1;
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<maze[i][j]<<'\t';
    //     }
    //     cout<<endl;
    // }

    int cnt = 0;

    while(true){
        pair<int, int> p = is_unvisited();
        if(p == pair<int, int>(-1, -1))break;
        bfs(p);
        cnt++;
    }

    cout<<cnt<<endl;
}