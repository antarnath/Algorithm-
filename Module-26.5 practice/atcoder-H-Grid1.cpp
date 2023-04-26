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
const ll MMM = 1e18 + 18;
ll dp[N][N];

ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b);}
  
int solve(vs &v, ll n, ll m){
    if(n == 0 and m == 0) return 1;
    if(v[n][m] == '#') return 0;
    if(dp[n][m] != -1) return dp[n][m];

    if(n == 0 and v[n][m] == '.'){
        dp[n][m] = solve(v, n, m-1) % MM;
        return dp[n][m];
    }
    if(m == 0 and v[n][m] == '.'){
        dp[n][m] = solve(v, n-1, m) % MM;
        return dp[n][m];
    }

    ll ans1 = solve(v, n, m-1) % MM;
    ll ans2 = solve(v, n-1, m) % MM;

    dp[n][m] = (ans1 + ans2) % MM;
    return dp[n][m];
}


void testCase(){
    ll n, m;
    cin >> n >> m;
    vs v;
    f(i, n){
        string s; cin >> s;
        v.pb(s);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(v, n-1, m-1) << endl;

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