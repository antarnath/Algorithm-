#include<bits/stdc++.h>
using namespace std;


int main(){
    priority_queue<int>pq;
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(a==1){
            int b;
            cin>>b;
            pq.push(b);
        }
        else{
            cout<<pq.top()<<endl;
            pq.pop();
        }
    }
}