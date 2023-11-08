
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
    arrays;
    ll s0 = 0, s1 = 0, mx = -INT_MAX;
    for(ll i=0; i<n; i++){
        s1+=a[i];
        if(s0<s1) s0 = s1;
        if(s1<0) s1 = 0;
        mx = max(mx,a[i]);
    }
    (mx<0)? cout<< mx<< endl : cout<< s0<< endl;
}
 
int main(){
    // test{
        solve();
    // }
}


