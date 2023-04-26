#include<bits/stdc++.h>
using namespace std;

int main()
{
    int b;
    cin>>b;
    vector<pair<int,int>>v;
    for(int i=0;i<b;i++){
        int n,m;
        cin>>n>>m;
        v.push_back({n,m});
    }
    sort(v.begin(),v.end());
    vector<pair<int,int>>cnt;

    bool found=true;
    cnt.push_back({v[0].first,v[0].second});
    for(int i=1;i<b;i++){
        for(int j=0;j<cnt.size();j++){
            if(v[i].first>cnt[j].second){
                found=false;
            }
        }
        if(found){
            cnt.push_back({v[i].first,v[i].second});
        }
    }
    cout<<cnt.size()<<endl;
}
