
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test int t; cin>> t; for(int tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; int a[n]; for(ll i=0; i<n; i++) scanf("%d",&a[i]);
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define N 200009
#define pll pair<ll,ll>
#define vll vector<ll>
#define pi acos(-1.0)
#define mod 1000000007
#define fastio std::ios::sync_with_stdio(false);
#define endl "\n"
#define invalid 1000000009
//follow sabit vi, all small case

vll compression(vll a){
    ll n = a.size();
    vector<pll> v;
    for(ll i=0; i<n; i++){
        v.pb(mp(a[i],i));
    }
    sort(v.begin(),v.end());
    ll r = 1;
    for(ll i=0; i<n; i++){
        if(i>0 && v[i].first!=v[i-1].first) r++;
        a[v[i].second] = r;
    }
    return a;
}

//ofstream ofs("out.txt");
void solve(){
    ll n; cin>> n;
    vll a(n);
    for(ll i=0; i<n; i++){
        cin>> a[i]; 
    }
    a = compression(a);
    for(ll i=0; i<n; i++){
        cout<< a[i]<< " ";
    }
    cout<< endl;
}

int main(){
    fastio;
    test{
        solve();
    }
    //ofs.close();
}
