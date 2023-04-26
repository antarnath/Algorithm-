#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j && arr[i][j]==1){
                cout<<"NO"<<endl;
                return 0;
            }
            if(arr[i][j] != arr[j][i]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;
    return 0;
}