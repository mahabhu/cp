
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test int t; cin>> t; for(int tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; ll a[n]; for(ll i=0; i<n; i++) scanf("%lld",&a[i]);
#define pb push_back
#define mp make_pair
//#define x first
//#define y second
#define N 500009
#define pll pair<ll,ll>
#define pi acos(-1.0)
#define mod 1000000007

void solve(){
    string s, q; cin>> s>> q;
    ll n = s.size();
    ll u = 0;
    for(ll i=1; i<n; i++){
        if(s[i-1]=='0' && q[i-1]=='0' && s[i]=='1' && q[i]=='1') u++;
    }
    (u==0)? cout<< "NO\n" : cout<< "YES\n";
}

int main(){
    test{
        solve();
    }
}


