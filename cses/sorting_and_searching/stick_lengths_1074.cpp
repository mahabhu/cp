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
    arrays;
    sort(a,a+n);
    ll s = 0;
    for(ll i=0; i<n; i++) s+=a[i];
    ll l = 0, r = n, m = s;
    for(ll i=0; i<n; i++){
        ll k;
        (i==0)? k = a[0] : k = a[i]-a[i-1];
        s+=(l-r)*k;
        m = min(m,s);
        l++;
        r--;
    }
    cout<< m<< endl;
}
 
int main(){
    //fastio
    // test{
        solve();
    // }
}


