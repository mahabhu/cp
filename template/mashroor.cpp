/*
priority_queue<string, vector<string>, greater<string> > pq; 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test int t; cin>> t; for(int tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; ll b[n]; for(ll i=0; i<n; i++) scanf("%lld",&b[i]);
#define edgeinput ll g, h; cin>> g>> h; v[g].pb(h); v[h].pb(g);
#define cases cout<< "Case "<< tc<< ": ";
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 200009
#define pll pair<ll,ll>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pi acos(-1.0)
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
#define pi acos(-1.0)
#define mod 998244353
#define endl "\n"
#define loop(X,Y,Z) for(ll X=Y; X<Z; X++)
#define yesno cout<< "YES\n" : cout<< "NO\n";
#define arrin(X,Y) ll X[Y]; for(ll i=0; i<Y; i++) cin>> X[i];    

void solve(){
    ll n, k; cin>> n>> k;
    loop(i,1,k+1) cout<< i<< " ";
    for(ll i=n; i>k; i--) cout<< i<< " ";
    cout<< endl;
}
 
int main(){
    fastio
    test 
        solve();
}
