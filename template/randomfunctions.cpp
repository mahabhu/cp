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
#define vb vector<ll>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pi acos(-1.0)
#define mod 998244353
#define endl "\n"



void permutation(ll n, ll i=0, vll word=vll(0,0), vb left=vb(0,0)){
    if(i==n){
        for(ll j=0; j<n; j++) cout<< word[j]<< " ";
        cout<< endl;
        return;
    }
    if(i==0){
        word = vll(n);
        left = vb(n,false);
    }
    for(ll j=0; j<n; j++){
        if(!left[j]){
            left[j]=true;
            word[i]=j;
            permutation(n,i+1,word,left);
            left[j]=false;
        }
    }
}

void solve(){
    permutation(3);
    // ll n; cin>> n;
    // ll a[n][3];
    // for(ll i=0; i<3; i++){
    //     for(ll j=0; j<n; j++){
    //         cin>> a[j][i];
    //     }
    // }
    
}

ll lift(ll a, ll b){
    if(b==0) return 1;
    ll k = lift(a,b/2);
    k*=k; k%=mod;
    if(b%2==1) k*=a;
    return k%mod;
}
 
 
ll ei(ll a){
    return lift(a, mod-2);
}
 
class modint{
    public:
    ll n;
    modint(ll n=0):n(n%mod){}
    modint(const modint& dt){ this->n=dt.n;}
    friend istream& operator>>(istream& os, modint& dt);
    friend ostream& operator<<(ostream& os, const modint& dt);
    bool operator == (const modint& dt) const{ return (n==dt.n); }
    bool operator != (const modint& dt) const{ return !(n==dt.n); }
    bool operator = (const modint& dt) { n=dt.n; return true; }
    modint operator * (const modint& dt){ return modint((n*dt.n)%mod); }
    modint operator / (const modint& dt){ return modint((n*ei(dt.n))%mod); }
    modint operator + (const modint& dt){ return modint((n+dt.n)%mod); }
    modint operator - (const modint& dt){ return modint((n-dt.n + mod)%mod); }
    modint operator ^ (const modint& dt){ return modint(lift(n,dt.n)); }
};
istream& operator>>(istream& os, modint& dt){ os >> dt.n; return os; }
ostream& operator<<(ostream& os, modint& dt){ os << dt.n; return os; }
 
int main(){
    // fastio
    // test 
        solve();
}


