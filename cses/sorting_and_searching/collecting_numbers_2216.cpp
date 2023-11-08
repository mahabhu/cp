#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test int t; cin>> t; for(int tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; ll a[n]; for(ll i=0; i<n; i++) scanf("%lld",&a[i]);
#define cases cout<< "Case "<< tc<< ": ";
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 200009
#define pll pair<ll,ll>
#define vll vector<ll>
#define pi acos(-1.0)
#define mod 1000000007
#define endl "\n"

void solve(){
    ll n; cin>> n;
    ll a[n+1];
    for(ll i=1; i<=n; i++){
        ll f; cin>> f;
        a[f]=i;
    }
    ll ans = 1;
    for(ll i=2; i<=n; i++){
        if(a[i-1]>a[i]) ans++;
    }
    cout<< ans<< endl;
}
 
int main(){
    //fastio
    // test{
        solve();
    // }
}


