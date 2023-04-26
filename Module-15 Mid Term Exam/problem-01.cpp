#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];


int main(){
    int n = 101;
    for(int i=2; i<=n; i++){
        for(int j=i; j<=n; j++){
            if((j)%i==0)
                adj_list[i].push_back(j);
            
        }
    }

    for(int i=0 ;i<=n;i++){
        for(int j=0;j<adj_list[i].size();j++){
            cout<<adj_list[i][j]<<" ";
        }cout<<endl;
    }

}