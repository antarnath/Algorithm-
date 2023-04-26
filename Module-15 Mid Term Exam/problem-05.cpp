#include<bits/stdc++.h>
using namespace std;
 
const int N = 55;
int arr[N][N];
int visited[N][N], level[N][N];
int n, m, h=0, w=0;
 
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
bool is_safe(pair<int, int> coord){
    if(coord.first >= 0 && coord.first < n &&
        coord.second >= 0 && coord.second < m){
            return true;
    }
    return false;
}
 
void dfs(pair<int, int>p){
    visited[p.first][p.second] = 1;
 
    for(int i=0;i<8;i++){
        int x = p.first + dx[i];
        int y = p.second + dy[i];
 
        if(arr[p.first][p.second]+1 == arr[x][y] && is_safe({x, y}) && !visited[x][y]){
            level[x][y] = level[p.first][p.second] + 1;
            dfs({x, y});
        }
    }
 
 
}
 
int find_ans(){
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(level[i][j] > ans) ans = level[i][j];
        }
    }
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            level[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    return ans;
}
 
 
 
int main(){
    int t = 1;
    
    while(cin>>n>>m){  
        if(n==0 && m==0)break;
 
        for(int i=0;i<n;i++){
            string st;
            cin>>st;
            for(int j=0;j<m;j++){
                int val = st[j]-'A'+1;
                arr[i][j] = val;
            }
        }
 
        
 
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1){
                    level[i][j] = 1;
                    dfs({i, j});
                    int val = find_ans();
                    if(val > ans) ans = val;
                }
            }
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
        t++;
    }
 
    return 0;
 
}
 

