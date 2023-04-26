#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>visited(1000, 0);

void addEdge(int x, int y){
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void bfs(int start){
    queue<int>q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int val = q.front();
        cout<<val<<" ";
        q.pop();

        for(int i=0; i<adj[val].size(); i++){
            if(adj[val][i] == 1 && visited[i]==0){
                visited[i] = true;
                q.push(i);
            }
        }
    }

}

int main(){
    int v = 6;
    adj = vector<vector<int>>(v, vector<int>(v, 0));



    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(2, 4);
    addEdge(2, 5);


    bfs(0);


}