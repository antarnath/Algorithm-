 
#include<bits/stdc++.h>
using namespace std;
 
int n, m;
const int N = 1005;
int maze[N][N];
int visited[N][N];
 
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
 
bool is_inside(pair<int , int> p){
    if((p.first>=0 && p.first < n) && (p.second>=0 && p.second<m)){
        return true;
    }
    return false;
}
 
bool is_safe(pair<int, int> p){
    if(maze[p.first][p.second]==0)return true;
    return false;
}
 
void dfs(pair<int , int> p){
    visited[p.first][p.second] = 1;
 
    for(int i=0; i<4; i++){
        int x = p.first + dx[i];
        int y = p.second + dy[i];
        pair<int , int> a = {x, y};
        if(is_inside(a) && is_safe(a) && !visited[x][y]){
            dfs(a);
        }
    }
}
 
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string input;
        cin>>input;
        for(int j=0; j<m; j++){
            if(input[j] == '#'){
                maze[i][j] = -1;
            }
        }
    }
 
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            pair<int , int> p = {i, j};
            if(!visited[i][j] && maze[i][j]==0){
                dfs(p);
                cnt++;
            }
        }
    }
 
    cout<<cnt<<endl;
}