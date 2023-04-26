#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int maze[N][N];
int visited[N][N], level[N][N];
vector<vector<pair<int,int>>> parent;
int n,m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool is_maze(pair<int, int> coord){
    if(coord.first>=0 && coord.first < n &&
        coord.second>=0 && coord.second < m){
            return true;
    }
    return false;
}

bool is_safe(pair<int, int> coord){
    if(maze[coord.first][coord.second]==0) return true;
    return false;
}

void bfs(pair<int, int> src){
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    parent[src.first][src.second] = {-1, -1};

    queue<pair<int, int>> q;
    q.push(src);

    while(!q.empty()){
        pair<int, int> head = q.front();
        int x = head.first;
        int y = head.second;
        q.pop();

        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int,int> adj_node = {new_x, new_y};

            if(is_maze(adj_node) && is_safe(adj_node) && !visited[new_x][new_y]){

                q.push(adj_node);
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                parent[new_x][new_y] = {x, y};
            }
        }
    }
}

pair<int, int> find_destination(){
    pair<int, int> a = {-1, -1};
    int b = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || i==n-1 ||j==0 ||j==m-1) && visited[i][j] && maze[i][j]==0){
                if(level[i][j] < b){
                    a = {i, j};
                }
            }
        }
    }

    return a;
    
}

int main(){
    cin>>n>>m;
    pair<int, int> src, des;
    for(int i=0;i<n;i++){
        string st;
        cin>>st;
        for(int j=0;j<m;j++){
            if(st[j]=='#' || st[j]=='M'){
                maze[i][j] = -1;
            }
            else if(st[j]=='A'){
                src = {i, j};
            }
        }
    }
    for(int i=0;i<n;i++){
        vector<pair<int,int>>v;
        for(int j=0;j<m;j++){
            v.push_back({0, 0});
        }
        parent.push_back(v);
    }

    bfs(src);

    des = find_destination();

    if(des.first==-1 && des.second==-1){
        cout<<"NO"<<endl;
        return 0;
    }

    stack<char> st;

    pair<int, int> selected = des;

    

    
    while(true){


        pair<int, int> val = parent[selected.first][selected.second];
        
        if(val.first==selected.first && val.second < selected.second){
            st.push('R');
        }
        else if(val.first==selected.first && val.second > selected.second){
            st.push('L');
        }
        else if(val.first>selected.first && val.second==selected.second){
            st.push('U');
        }
        else if(val.first<selected.first && val.second==selected.second){
            st.push('D');
        }

        if(val == src) break;

        selected = val;

    }

    cout<<"YES"<<endl;
    cout<<level[des.first][des.second]<<endl;
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
  

    return 0;

}


/* 
5 8
########
#M..A..#
#.#.M#.#
#M#..#.#
#.######
 */