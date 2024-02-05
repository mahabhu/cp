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