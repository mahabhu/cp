
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test int t; cin>> t; for(int tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; ll a[n]; for(ll i=0; i<n; i++) scanf("%lld",&a[i]);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 200009
#define pll pair<ll,ll>
#define vll vector<ll>
#define pi acos(-1.0)
#define mod 1000000007



void solve(){
    ll n, x; cin>> n>> x;
    ll a[n];
    for(ll i=0; i<n; i++) cin>> a[i];
    sort(a,a+n);
    ll ans = 0;
    ll r=0;
    for(ll i=n-1; i>=r; i--){
        if(a[i]+a[r]<=x) r++;
        ans++;
    }
    cout<< ans<< endl;
}
 
int main(){
    // test{
        solve();
    // }
}


