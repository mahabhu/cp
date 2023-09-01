
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
    ll n = 0;
    string s; cin>> s;
    for(ll i=0; i<9; i++){
        if(n==0){
            if(s[i]=='3') n=3;
            else if(s[i]=='1') n = 1;
        }
    }
    (n==3)? cout<< "31\n" : cout<< "13\n";
}

int main(){
    test{
        solve();
    }
}
