#include<bits/stdc++.h>
using namespace std;



int main(){
    int nodes = 4;
    int matrix[nodes][nodes] = {} ;

    for(int i = 0; i < nodes; i++){
        int a, b;
        cin>>a>>b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}