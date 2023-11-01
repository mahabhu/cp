
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
    string s; cin>> s;
    ll mx = 1, n = s.size(), j = 1;
    for(ll i=1; i<n; i++){
        if(s[i-1]==s[i]) j++;
        else j = 1;
        mx = max(mx,j);
    }
    cout<< mx<< endl;
}

int main(){
    // test{
        solve();
    // }
}


