#include<bits/stdc++.h>
using namespace std;
int sum = 0;
void sum_of(int n){

    if(n==0) return;

    sum += n%10;
    sum_of(n/10);
}

int main(){
    int n;
    cin>>n;

    sum_of(n);

    cout<<sum<<endl;
}