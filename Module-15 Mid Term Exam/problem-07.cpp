#include<bits/stdc++.h>
using namespace std;


vector<int>vt[1009], cost[1009];
int dis[1009], n;

struct node{
    int u, w;
    node(int a, int b){
        u=a, w=b;
    }
    bool operator < (const node & p)const{
        return p.w<w;
    }
};

void dijkstra(int st){
    priority_queue<node>q;
    for(int i=0;i<n;i++) {
        dis[i]=20001;
    }
    dis[st]=0;
    q.push(node(st, 0));
    while(!q.empty()){
        node top=q.top();
        q.pop();
        int u=top.u;
        int sz=vt[u].size();
        for(int i=0;i<sz;i++){
            int v=vt[u][i];
            int temp=max(dis[u], cost[u][i]);
            if(temp<dis[v]){
                dis[v]=temp;
                q.push(node(v, dis[v]));
            }
        }
    }
}

int main(){
    int e, u, v, w, m, t, cs=1;
    cin>>t;
    while(t--){
        cin>>n>>e;
        for(int i=0;i<e;i++){
            cin>>u>>v>>w;
            vt[u].push_back(v);
            vt[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        cin>>m;
        dijkstra(m);
        cout<<"Case "<<cs++<<":"<<endl;
        for(int i=0;i<n;i++){
            if(dis[i]==20001)cout<<"Impossible"<<endl;
            else cout<<dis[i]<<endl;
        }
        for(int i=0;i<n;i++){
            vt[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}