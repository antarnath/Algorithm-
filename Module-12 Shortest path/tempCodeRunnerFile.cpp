#include<bits/stdc++.h>
using namespace std;

int number_of_factor(int n){
    int a = 2;
    int count = 0;
    while(n>1){
        if(n%a==0){
            count++;
            n = n/a;
        }
        else{
            a++;
        }
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<number_of_factor(n)<<endl;
    }
}