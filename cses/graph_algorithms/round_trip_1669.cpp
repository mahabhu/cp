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
void clrb(ll n){ for(ll i=0; i<=n; i++) b[i]=0; }
void clrv(ll n){ for(ll i=0; i<=n; i++) v[i].clear(); }
void clrd(ll n){ for(ll i=0; i<=n; i++) d[i]=INT_MAX; }
void clrp(ll n){ for(ll i=0; i<=n; i++) p[i]=-1; }
ll dfs(ll u, ll w){
    b[u]=true;
    // cout<< u<< "---+\n";
    for(ll i=0; i<v[u].size(); i++){
        ll k = v[u][i];
        if(!b[k]){
            p[k]=u;
            ll g = dfs(k, u);
            if(g!=-2){
                return g;
            }
        }
        else if(k!=w){
            p[k]=u;
            return k;
        }
    }
    return -2;
}
ll bfs(ll u){
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
            else if((d[k]+d[u])%2==0) return 1;
        }
    }
    return 0;
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
    for(ll i=1; i<=n; i++){
        if(!b[i]){
            ll u = dfs(i,-2);
            // cout<< u<< " jal\n";
            if(u==-2) continue;
            vll ans;
            ans.pb(u);
            ll h = p[u];
            while(h!=u){
                ans.pb(h);
                h = p[h];
            }
            ans.pb(u);
            cout<< ans.size()<< endl;
            for(ll i=0; i<ans.size(); i++) cout<< ans[i]<< " ";
            cout<< endl;
            return;
        }
    }
    cout<< "IMPOSSIBLE\n";
    return;
}
 
int main(){
    //fastio
    // test{
        solve();
    // }
}


