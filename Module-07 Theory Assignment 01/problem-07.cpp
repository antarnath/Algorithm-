#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt = 0;
    for(int i=100;i>0;i/=2){
        cnt=0;
        for(int j=0;j<i;j++){
            cnt++;
        }
        cout<<cnt<<endl;
    }
    // cout<<cnt<<endl;
}