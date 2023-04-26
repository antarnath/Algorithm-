#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(n%m==0){
        int ans = min((n/m)*b , n*a);
        cout<<ans<<endl;
    }
    else if(n<m){
        int ans = min(b, n*a);
        cout<<ans<<endl;
    }
    else{
        int ans = min( (n/m)*b+b, (n/m)*b+(n%m)*a);
        ans = min(ans, n*a);
        cout<<ans<<endl;
    }
    return 0;
}