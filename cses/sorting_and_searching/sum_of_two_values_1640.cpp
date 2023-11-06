
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

struct xD{
    ll va, in;
    bool operator<(const xD &y) const{
        if(va==y.va) return in<y.in;
        return va<y.va;
    }
};



void solve(){
    ll n, x; cin>> n>> x;
    xD a[n];
    for(ll i=0; i<n; i++){
        cin>> a[i].va;
        a[i].in = i+1;
    }
    sort(a,a+n);
    ll r = n-1;
    for(ll i=0; i<n; i++){
        while(a[i].va+a[r].va>x && r>i) r--;
        if(r<=i){
            cout<< "IMPOSSIBLE\n";
            return;
        }
        if(a[i].va+a[r].va==x){
            cout<< a[i].in<< " "<< a[r].in<< endl;
            return;
        }
    }
}
 
int main(){
    // test{
        solve();
    // }
}


