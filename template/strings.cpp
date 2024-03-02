/*
priority_queue<string, vector<string>, greater<string> > pq; 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test int t; cin>> t; for(int tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; ll b[n]; for(ll i=0; i<n; i++) cin>> b[i]; //scanf("%lld",&b[i]);
#define cases cout<< "Case "<< tc<< ": ";
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define mp make_pair
#define newedge ll g,h; cin>> g>> h; v[g].pb(h); v[h].pb(g);
#define fi first
#define se second
#define N 2009
#define pll pair<ll,ll>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpair vector<pll>
#define pi acos(-1.0)
#define mod 998244353
#define endl "\n"
#define loop(X,Y,Z) for(ll X=Y; X<Z; X++)
#define yesno cout<< "YES\n" : cout<< "NO\n";
#define arrin(X,Y) ll X[Y]; for(ll i=0; i<Y; i++) cin>> X[i];


vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n,0);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> p(n,0);
    for (int i = 1; i < n; i++) {
        int j = p[i-1];
        while (j > 0 && s[i] != s[j])
            j = p[j-1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

bool stopsufarr(vll a, ll h){
    ll n = a.size();
    vll cnt(n,0);
    ll unq = 0, mn = 1e18;
    for(auto k : a){
        cnt[k]++;
        if(cnt[k]==1){
            unq++;
        }
        mn = min(mn,k);
    }
    return (unq<=h||cnt[mn]==1);
}


vpair radixsort(vpair v){
    ll n=v.size(), e=1e7;
        vll cnt(n);
        for(ll i=0; i<n; i++) cnt[v[i].first%e]++;
        vpair a_new(n);
        vll pos(n);
        pos[0]=0;
        for(ll i=1; i<n; i++) pos[i]=pos[i-1]+cnt[i-1];
        for(ll i=0; i<n; i++){
            ll k=v[i].first%e;
            a_new[pos[k]]=v[i];
            pos[k]++;
        }
        v = a_new;

        cnt = vll(n,0);
        for(ll i=0; i<n; i++) cnt[v[i].first/e]++;
        a_new = vpair(n,mp(0,0));
        pos = vll(n,0);
        pos[0]=0;
        for(ll i=1; i<n; i++) pos[i]=pos[i-1]+cnt[i-1];
        for(ll i=0; i<n; i++){
            ll k=v[i].first/e;
            a_new[pos[k]]=v[i];
            pos[k]++;
        }
        v = a_new;
    return v;
}

vll sufarr(string s, ll h){
    ll n=s.size();
    if(h==1){
        ll b[128]={0};
        for(ll i=0; i<n; i++) b[s[i]]++;
        ll k=0;
        for(ll i=0; i<128; i++){
            if(b[i]>0){
                b[i]=k;
                k++;
            }
        }
        vll a(n);
        for(ll i=0; i<n; i++) a[i]=b[s[i]];
        return a;
    }
    vpair v(n);
    vll a=sufarr(s,h/2);
    if(stopsufarr(a,h/2)) return a;
    // cout<< h/2<< " : ";
    // for(ll i=0; i<a.size(); i++) cout<< a[i]<< " ";
    // cout<< endl;
    ll e=1e7;
    for(ll i=0; i<n; i++) v[i]= mp(a[i]*e+a[(i+h/2)%n],i);
    v = radixsort(v);
    for(ll i=0; i<n; i++) a[v[i].second]=i;
    for(ll i=1; i<n; i++){
        if(v[i].first==v[i-1].first) a[v[i].second]=a[v[i-1].second];
    }
    return a;
}

vll suffixarray(string s, bool dollar=true){
    string q=s;
    if(dollar) q=q+'$';
    ll n=q.size();
    ll h=1;
    while(h<n) h+=h;
    auto a = sufarr(q,h);
    // cout<< h<< " : ";
    // for(ll i=0; i<a.size(); i++) cout<< a[i]<< " ";
    // cout<< endl;
    // cout<< q<< endl;
    return a;
}

void suffprint(string s){
    vll a = suffixarray(s);
    s = s+'$';
    ll n = s.size();
    vll b(n);
    for(ll i=0; i<n; i++) b[a[i]]=i;
    for(ll i=0; i<n; i++){
        for(ll j=b[i]; j<b[i]+n; j++){
            cout<< s[j%n];
        }
        cout<< endl;
    }
}

void solve(){
    string s; cin>> s;
    auto z = z_function(s);
    auto p = prefix_function(s);
    ll n = s.size();
    for(ll i=0; i<n; i++) cout<< z[i]<< " "; cout<< endl;
    for(ll i=0; i<n; i++) cout<< p[i]<< " "; cout<< endl;
}
 
int main(){
    fastio
    test 
        solve();
}