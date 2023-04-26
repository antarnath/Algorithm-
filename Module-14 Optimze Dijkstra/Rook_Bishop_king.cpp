#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int maze[N][N], visited[N][N], level[N][N]; 
vector<vector<pair<int,int>>> parent;
int r1, c1, r2, c2;
int dx1[] = {-1, -1, 1, 1};
int dy1[] = {-1, 1, -1, 1};

bool is_safe(pair<int, int> coord){
    if((coord.first >0 && coord.first <= 8) && 
        coord.second >0 && coord.second <= 8){
            return true;
    }
    return false;
}
void is_bishop(){
    queue< pair<int, int> > q;
    visited[r1][c1] = 1;
    q.push({r1, c1});

    while(!q.empty()){
        // cout<<"antar"<<" ";
        pair<int, int> head = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int x = dx1[i] + head.first;
            int y = dy1[i] + head.second;

            if(!visited[x][y] && is_safe({x, y})){
                parent[x][y] = {head.first, head.second};
                visited[x][y] = 1;
                q.push({x, y});
            }
        }
    }
}

int main(){
    
    cin >> r1 >> c1 >> r2 >> c2;

    if(r1==r2 || c1==c2){
        cout<<1<<" ";
    }
    else{
        cout<<2<<" ";
    }

    cout<<endl;

    for(int i=0;i<=8;i++){
        vector<pair<int,int>>v;
        for(int j=0;j<=8;j++){
            v.push_back({0, 0});
        }
        parent.push_back(v);
    }

    is_bishop();
    int cnt = 0;
    int a = r1, b = c1;
    int c = r2, d = c2;
    while(true){
        pair<int, int> p = parent[c][d];
        a = p.first, b = p.second;
        if(a > c && b > d){
            
        }
    }

    for(int i=1; i<=8;i++){
        for(int j=1;j<=8;j++){
            printf("(%d, %d)\t", parent[i][j].first, parent[i][j].second);
        }
        cout<<endl;
    }
}