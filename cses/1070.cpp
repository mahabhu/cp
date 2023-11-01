
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
#define N 200009
#define pll pair<ll,ll>
#define vll vector<ll>
#define pi acos(-1.0)
#define mod 1000000007

void solve(){
    ll n; cin>> n;
    if(n==2 || n==3) cout<< "NO SOLUTION\n";
    else{
        for(ll i=2; i<=n; i+=2) cout<< i<< " ";
        for(ll i=1; i<=n; i+=2) cout<< i<< " ";
        cout<< endl;
    }
}

int main(){
    // test{
        solve();
    // }
}


