
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
#define mod 998244353
#define fastio std::ios::sync_with_stdio(false);
#define endl "\n"
#define invalid 1000000009

ll a[N];

ll binpow(ll a, ll b){
    a%=mod;
    if(b==0) return 1;
    ll k= binpow(a,b/2);
    k*=k;
    k%=mod;
    if(b%2==1) k*=a;
    return k%mod;
}

ll ei(ll n){
    return binpow(n,mod-2);
}

ll ans(ll l, ll r){
    if(l>=r) return 0;
    ll k = a[r-1];
    if(k==0) return ((r-l)*(r-l))%mod;
    ll h = -1;
    while(k){
        k/=2;
        h++;
    }
    h = (1<<h);
    ll e = r-1;
    while(e-1>=l && a[e-1]>=h) e--;
    k = r-e;
    ll cnt=(k*k)%mod;
    cnt+=(3*(e-l)*(r-e))%mod;
    cnt%=mod;
    for(ll i=e; i<r; i++){
        a[i]-=h;
    }
    return (cnt+ans(l,e)+ans(e,r))%mod;
}

//ofstream ofs("out.txt");
void solve(){
    ll n; cin>> n;
    for(ll i=0; i<n; i++) cin>> a[i];
    sort(a,a+n);
    ll k = ans(0,n);
    //cout<< k<< "---\n";
    k*=ei((n*n)%mod);
    k%=mod;
    cout<< k<< endl;
}

int main(){
    fastio;
    test{
        solve();
    }
    //ofs.close();
}
