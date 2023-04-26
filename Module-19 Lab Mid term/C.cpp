#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int > adj_list[N];


int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int a;
        cin>>a;
        if(a==1){
            int u, v;
            cin>>u>>v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        else if(a==2){
            int x;
            cin>>x;
            for(int i=0;i<adj_list[x].size();i++){
                cout<<adj_list[x][i]<<" ";
            }
            cout<<endl;
        }
    }
}