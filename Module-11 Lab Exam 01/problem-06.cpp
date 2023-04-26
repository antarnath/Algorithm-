#include<bits/stdc++.h>
using namespace std;

const int N=2e5;
vector<int> adj_list[N];
vector<int>visited(N);
vector<int> indegree(N);
int n,m;
queue<int>st;

void bfs(){
    queue<int> q;
    
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
            visited[i] = 1;
        }
    }

    while(!q.empty()){
        int val = q.front();
        st.push(val);
        q.pop();

        for(int adj_node : adj_list[val]){
            indegree[adj_node]--;
            if(indegree[adj_node]==0 && visited[adj_node]==0){
                q.push(adj_node);
                visited[adj_node] = 1;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        indegree[v]++;
        adj_list[u].push_back(v);
    }

    bfs();

    if(st.size()==n){ 
        while(!st.empty()){
            cout<<st.front()<<" ";
            st.pop();
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
    


}