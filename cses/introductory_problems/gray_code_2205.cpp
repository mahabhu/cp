
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

void gray(ll n, ll m){
    if(n==0) return;
    if(m<(1<<(n-1))){
        cout<< "0";
        gray(n-1,m);
    }
    else{
        cout<< "1";
        gray(n-1,(1<<n)-1-m);
    }
    return;
}

void solve(){
    ll n; cin>> n;
    for(ll i=0; i<(1<<n); i++){
        gray(n,i);
        cout<< endl;
    }
}
 
int main(){
    // test{
        solve();
    // }
}


