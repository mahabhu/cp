
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

void wordperm(vll v, string s, ll n){
    if(n==0){
        cout<< s<< endl;
        return;
    }
    for(ll i=0; i<26; i++){
        if(v[i]){
            vll g = v;
            g[i]--;
            char c = 'a'+i;
            string q = s+c;
            wordperm(g,q,n-1);
        }
    }
}

void solve(){
    string s; cin>> s;
    ll n = s.size();
    vll v(26,0);
    ll ans = 1;
    for(ll i=0; i<n; i++){
        ans*=(i+1);
        v[(s[i]-'a')]++;
        ans/=v[(s[i]-'a')];
    }
    s = "";
    cout<< ans<< endl;
    wordperm(v,s,n);
}
 
int main(){
    // test{
        solve();
    // }
}


