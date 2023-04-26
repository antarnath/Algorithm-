#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n==1)return 1;

    return n + sum(n-1);
}

bool check_palindrome(string s){
    if(s=="" || s.size()==1) return true;

    return check_palindrome(s.substr(1, s.size()-2)) && (s[0]==s.back());
}

int main(){
    string s;
    cin>>s;
    cout<<check_palindrome(s);
}