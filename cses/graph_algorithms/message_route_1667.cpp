#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test int t; cin>> t; for(int tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; ll a[n]; for(ll i=0; i<n; i++) scanf("%lld",&a[i]);
#define cases cout<< "Case "<< tc<< ": ";
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 200009
#define pll pair<ll,ll>
#define vll vector<ll>
#define pi acos(-1.0)
#define mod 1000000007
#define endl "\n"

vll v[N];
bool b[N];
ll d[N], p[N];
void clrb(ll n){ for(ll i=0; i<=n; i++) b[i]=false; }
void clrv(ll n){ for(ll i=0; i<=n; i++) v[i].clear(); }
void clrd(ll n){ for(ll i=0; i<=n; i++) d[i]=INT_MAX; }
void clrp(ll n){ for(ll i=0; i<=n; i++) p[i]=-1; }
void dfs(ll u){
    b[u]=true;
    for(ll i=0; i<v[u].size(); i++){
        ll k = v[u][i];
        if(!b[k]){
            dfs(k);
        }
    }
    return;
}
void bfs(ll u){
    queue<ll> q;
    d[u]=0;
    b[u]=true;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(ll i=0; i<v[u].size(); i++){
            ll k = v[u][i];
            if(!b[k]){
                b[k]=true;
                d[k] = d[u]+1;
                p[k]=u;
                q.push(k);
            }
        }
    }
    return;
}

void solve(){
    ll n, m; cin>> n>> m;
    for(ll i=0; i<m; i++){
        ll g, h; cin>> g>> h;
        v[g].pb(h);
        v[h].pb(g);
    }
    clrb(n);
    clrd(n);
    clrp(n);
    ll x=1, y=n; //cin>> x>> y;
    bfs(x);
    if(d[y]==INT_MAX){
        cout<< "IMPOSSIBLE\n";
        return;
    }
    vll ans;
    while(y!=x){
        ans.pb(y);
        y=p[y];
    }
    cout<< ans.size()+1<< endl;
    cout<< x<< " ";
    for(ll i=ans.size()-1; i>=0; i--) cout<< ans[i]<< " ";
    cout<< endl;
}
 
int main(){
    //fastio
    // test{
        solve();
    // }
}


