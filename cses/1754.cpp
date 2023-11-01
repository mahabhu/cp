
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

ll lift(ll a, ll b){
    if(b==0) return 1;
    ll k = lift(a,b/2);
    k*=k; k%=mod;
    if(b%2==1) k*=a;
    return k%mod;
}

void solve(){
    ll a, b; cin>> a>> b;
    ((a+b)%3==0 && a<=b+b && b<=a+a)? cout<< "YES\n" : cout<< "NO\n";
}
 
int main(){
    test{
        solve();
    }
}


