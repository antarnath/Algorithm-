#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin>>a;
    vector<pair<int,int>>v;
    for(int i=0;i<a;i++){
        int n,m;
        cin>>n>>m;
        v.push_back({n,m});
    }
    sort(v.begin(),v.end());

    bool found=false;
    for(int i=0;i<a;i++){
       for(int j=i+1;j<a;j++){
            if(v[i].second<v[j].first)
            {
                cout<<i<<" "<<j<<endl;
                found=true;
                break;
            }
            if(j==a-1){
                found=false;
                cout<<"break"<<endl;
                break;
            }
       }
    }
    if(found==false)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
