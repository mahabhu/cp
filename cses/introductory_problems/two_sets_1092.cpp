
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

ll o2n(ll n){
    return n*(n+1)/2;
}

void solve(){
    ll n; cin>> n;
    ll m = o2n(n);
    if((n*(n+1))%4==0){
        cout<< "YES\n";
        ll l=1, r=n;
        while(l<r){
            ll m1 = (l+r)/2;
            ll m2 = m1+1;
            ll f1 = o2n(m1);
            ll f2 = o2n(m2);
            if(f1+f1<m && f2+f2>=m){
                l = m2;
                r = m2;
            }
            if(f1+f1>=m) r = m1;
            else l = m2;
        }
        ll k = o2n(l);
        (k*2==m)? cout<< l<< endl : cout<< l-1<< endl;
        for(ll i=1; i<=l; i++){
            if(k-m/2 != i) cout<< i<< " ";
        }
        cout<< endl;
        (k*2==m)? cout<< n-l<< endl : cout<< n-l+1<< endl<< k-m/2<< " ";
        for(ll i=l+1; i<=n; i++){
            cout<< i<< " ";
        }
        cout<< endl;
    }
    else{
        cout<< "NO\n";
    }
}
 
int main(){
    // test{
        solve();
    // }
}


