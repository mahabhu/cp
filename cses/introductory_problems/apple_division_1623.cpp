
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

ll a[1<<20]={0};

void solve(){
    ll n; cin>> n;
    ll sum = 0;
    for(ll i=0; i<n; i++){
        ll f; cin>> f;
        for(ll j=0; j<(1<<i); j++){
            a[j+(1<<i)] = a[j]+f;
        }
        sum+=f;
    }
    ll ans = INT_MAX;
    for(ll i=0; i<(1<<n); i++){
        ans = min(ans,abs(sum-a[i]*2));
    }
    cout<< ans<< endl;
}
 
int main(){
    // test{
        solve();
    // }
}


