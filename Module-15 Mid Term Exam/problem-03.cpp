#include<bits/stdc++.h>
using namespace std;

const int N = 102;
vector<int> adj_list[N];
vector<int> ans;
int visited[N];

void dfs(int i, vector<int>&v){
    visited[i] = true;
    v.push_back(i);
    if(adj_list[i].size()==0 && ans.size() < v.size()){
        ans = v;
    }

    for(auto adj_node : adj_list[i]){
        if(!visited[adj_node]){
            dfs(adj_node, v);
        }
    }
    visited[i] = 0;
    v.pop_back();
}


int main(){
    for(int i=2; i<N; i++){
        for(int j=i+1; j<N; j++){
            if((j)%i==0)
                adj_list[i].push_back(j);
            
        }
    }


    for(int i=2;i<N;i++){
        vector<int>v;
        
        dfs(i, v);
    }

    cout<<"Length : "<<ans.size()<<endl;
    cout<<"Path: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;

}