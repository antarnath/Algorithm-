#include<bits/stdc++.h>
using namespace std;

const int N=1005;
int maze[N][N];
int visited[N][N];
int level[N][N];
int n,m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> coord){
    if((coord.first >=0 && coord.first <n) &&
        coord.second>=0 && coord.second<m){
            return true;
    }
    return false;
}

bool is_safe(pair<int, int> coord){
    if(maze[coord.first][coord.second]==0)return true;
    return false;
}


void bfs(pair<int, int> src){

    queue<pair<int, int> >q;
    q.push(src);
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;

    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;
        
        for(int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int, int> adj_node = {new_x, new_y};

            if(is_inside(adj_node) && is_safe(adj_node) && !visited[new_x][new_y]){
                q.push(adj_node);
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
            }
        }
    }


}

int main(){
    cin>>n>>m;
    pair<int, int> src;
    for(int i=0;i<n;i++){
        string st;
        cin>>st;
        for(int j=0;j<m;j++){
            if(st[j]=='#' || st[j]=='M'){
                maze[i][j] = 1;
            }
            else if(st[j]=='A'){
                src = {i, j};
            }
        }
    }

    bfs(src);

    bool check = false;
    int val = INT_MAX;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((i==0 || j==0 || i==n-1 || j==m-1) && level[i][j]){
                check = true;
                if(level[i][j] < val) val = level[i][j];
            }
        }
    }

    if(check){
        cout<<"YES"<<endl;
        cout<<val<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;

}


/* 

########
A....M.#
.#.#M..#
...M####
##.#####
.MM#####

 */