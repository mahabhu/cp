
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

struct treenode{
    ll sum;
};

treenode tree[4*N];
ll a[N], lazy[4*N];

void raise(ll e){
    tree[e].sum = (tree[e+e].sum+tree[e+e+1].sum)%mod;
    return;
}

void build(ll l, ll r, ll e){
    if(r-l==1){
        tree[e].sum = 0;
        a[l] = 0;
        return;
    }
    ll m = (r+l)/2;
    build(l,m,e+e);
    build(m,r,e+e+1);
    raise(e);
    return;
}

void upd(ll l, ll r, ll e, ll i, ll k){
    if(r-l==1){
        a[l] = (a[l]+k+1)%mod;
        tree[e].sum = a[l];
        return;
    }
    ll m = (r+l)/2;
    if(i<m) upd(l,m,e+e,i,k);
    else upd(m,r,e+e+1,i,(k+tree[e+e].sum)%mod);
    raise(e);
    return;
}

vll compression(vll a){
    set<ll> s;
    ll n = a.size();
    ll mn = INT_MAX;
    for(ll i=0; i<n; i++){
        s.insert(a[i]);
    }
    ll c = 1;
    map<ll,ll> M;
    for(set<ll>::iterator it = s.begin(); it!=s.end(); it++){
        M[*it] = c;
        c++;
    }
    for(ll i=0; i<n; i++){
        a[i] = M[a[i]]; 
    }
    return a;
}


//ofstream ofs("out.txt");
void solve(){
    ll n; cin>> n;
    vll b(n);
    for(ll i=0; i<n; i++) cin>> b[i];
    b = compression(b);
    build(1,n+1,1);
    for(ll i=0; i<n; i++){
        upd(1,n+1,1,b[i],0);
    }
    ll ans = 0;
    for(ll i=1; i<=n; i++){
        ans = (ans+a[i])%mod;
    }
    cout<< ans<< endl;
}

int main(){
    fastio;
    //test{
        solve();
    //}
    //ofs.close();
}
