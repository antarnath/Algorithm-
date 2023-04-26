#include<bits/stdc++.h>
using namespace std;

void reverse_st(string st){
    if(st.size()==0) return;
    reverse_st(st.substr(1));
    cout<<st[0];
}

int main(){
    string st;
    cin>>st;

    reverse_st(st);
}