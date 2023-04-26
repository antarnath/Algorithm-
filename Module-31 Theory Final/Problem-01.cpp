#include<bits/stdc++.h>
using namespace std;



int main(){
    int n; cin >> n;
    vector<vector<int> > ar(n, vector<int>(n));
    vector<int> adj_list[n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> ar[i][j];
            if(ar[i][j] == 1) adj_list[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j : adj_list[i]) cout << j << " ";
        cout << endl;
    }

}