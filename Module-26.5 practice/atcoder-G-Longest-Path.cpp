/* 
    Author : Antar chandra Nath
    
*/
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int lli;
#define fast        ios::sync_with_stdio(0);cin.tie(0);cin.tie(0);
#define endl        "\n"
#define pb          push_back
#define po          pop_back
#define mp          make_pair
#define sz(x)       x.size()
#define all(x)      x.begin(), x.end()
#define srt(x)      sort(all(x))
#define rstr(x)     sort(all(x), greater<ll>())
#define fi          first 
#define se          second 
#define ln          int n; cin>>n
#define lx          ll x; cin>>x
#define lm          ll m; cin>>m
#define f(i,n)      for(ll i=0;i<n;i++)
#define f1(i,n)     for(ll i=1;i<=n;i++)
#define fn(i,n)     for(ll i=n-1;i>=0;i--)
#define fa(it,n)    for(auto it:n)   
#define vl          vector<ll>
#define vs          vector<string>
#define vvl         vector<vector<ll>>
#define yes         cout << "YES" << endl
#define no          cout << "NO" << endl
#define mcl         map<char, ll> 
#define ml          map<ll, ll>
#define pi          pair<ll, ll>
#define ss           " "

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
const ll N = 1e3 + 7;
const ll NN = 1e5 + 7;
const ll MM = 1e9 + 7;
const ll MMM = 1e18 + 7;
vl adj_list[NN], store;
bool visited[NN];
ll dp[NN];

ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b);}
  
void dfs(ll node){
    visited[node] = 1;
    for(ll i=0;i<sz(adj_list[node]);i++){
        ll to = adj_list[node][i];
        if(visited[to] == 0){
            dfs(to);
        }
    }
    store.pb(node);
}

ll solve(){
    ll ans = 0;
    fa(i, store){
        fa(it, adj_list[i]){
            dp[i] = max(dp[i], dp[it] + 1);
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

void testCase(){
    ln; lm;
    f(i, m){
        ll x, y; cin >> x >> y;
        adj_list[x].pb(y);
    }

    f1(i, n){
        if(!visited[i]) dfs(i);
    }

    cout << solve() << endl;
    return;
}
 
int main(){
    fast;
    int t(1);
    // cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}