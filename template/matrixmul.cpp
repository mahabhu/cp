/*
priority_queue<string, vector<string>, greater<string> > pq; 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test int t; cin>> t; for(int tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; ll b[n]; for(ll i=0; i<n; i++) scanf("%lld",&b[i]);
#define cases cout<< "Case "<< tc<< ": ";
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 200009
#define pll pair<ll,ll>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pi acos(-1.0)
#define mod 998244353
#define endl "\n"


// vvll matmul(vvll a, vvll b){
//     ll n = a.size();
//     ll m = a[0].size();
//     ll o = b[0].size();
//     vvll c(n);
//     for(ll i=0; i<n; i++){
//         vll g(o,0);
//         c[i]=g;
//         for(ll j=0; j<o; j++){
//             for(ll k=0; k<m; k++){
//                 c[i][j]+=(a[i][k]*b[k][j])%mod;
//                 c[i][j]%=mod;
//             }
//         }
//     }
//     return c;
// }

// vll matmul(vvll a, vll b){
//     vvll g(1);
//     g[0]=b;
//     vvll d = matmul(a,g);
//     return d[0];
// }


void solve(){
    arrays;
    ll dp[2][12]={0};
    for(ll i=0; i<n; i++){
        
    }
}
 
int main(){
    fastio
    // test 
        solve();
}


