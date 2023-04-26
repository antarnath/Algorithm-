#include<bits/stdc++.h>
using namespace std;


void int_to_binary(int decimal, string &binary){
    if(!decimal)return;
    binary = to_string(decimal%2) + binary;
    int_to_binary(decimal/2, binary);
}


int main(){
    int decimal;
    cin >> decimal;
    if(decimal == 0){
        cout<<"0"<<endl;
        return 0;
    }
    string binary = "";
    int_to_binary(decimal, binary);
    cout<<binary;
}