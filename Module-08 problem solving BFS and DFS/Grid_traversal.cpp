/* 

5 8
########
#.A#...#
####.#B#
#......#
########

output:
    YES
    9

(x, y) --> right -->(x, y+1);
       --> left  -->(x, y-1);
       --> up    -->(x-1, y);
       --> down  -->(x+1, y);

dx[] = {0, 0, -1, 1}
dy[] = {1, -1, 0, 0}

*/


#include<bits/stdc++.h>
using namespace std;

const int N = 2002;

int maze[N][N];
int visited[N][N];
int level[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair< int, int > coord){
    if((coord.first>=0 && coord.first < n) && 
        (coord.second >= 0 && coord.second < m)){
            return true;
    }
    return false;
}

bool is_safe(pair< int , int > coord){
    if(maze[coord.first][coord.second] == 0)    return true;
    return false;
}

void bfs(pair<int, int> src){
    queue< pair<int, int> > q;
    q.push(src);
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;

    while(!q.empty()){
        pair< int, int > head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair< int, int > adj_node = {new_x, new_y};

            if(is_inside(adj_node) && is_safe(adj_node) && !visited[adj_node.first][adj_node.second]){
                q.push(adj_node);
                visited[adj_node.first][adj_node.second] = 1;
                level[adj_node.first][adj_node.second] = level[head.first][head.second] + 1;
            }
        }

    }
}


int main(){
    cin >> n >> m;

    pair<int, int> src, des;

    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        for(int j=0; j<m; j++){
            if(input[j] == '#'){
                maze[i][j] = -1;
            }
            else if(input[j] == 'A'){
                src = {i, j};
            }
            else if(input[j] == 'B'){
                des = {i, j};
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<maze[i][j]<<'\t';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    bfs(src);

    if(visited[des.first][des.second]){
        cout<<"YES"<<endl;
        cout<<level[des.first][des.second]<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    

}


