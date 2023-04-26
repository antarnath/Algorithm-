#include<bits/stdc++.h>
using namespace std;
 
const int N = 10^5;
vector<int>v;
 
int stone(int n){
    if(n==0) return 0;
    if(n==1) return abs(v[0]-v[1]);
 
    if(abs(v[n] - v[n-1]) < abs(v[n] - v[n-2]))
        return abs(v[n-1] - v[n]) + stone(n-1);
    else
        return abs(v[n-2] - v[n]) + stone(n-2);
}
 
 
int main(){
    int n;
    cin>>n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
 
    cout<<stone(n-1);
}