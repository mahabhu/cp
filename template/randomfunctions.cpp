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

ll ei(ll a){ return lift(a, mod-2); }
 
class ${
    public:
    ll n;
    $(ll n=0):n(n%mod){}
    $(const $& dt){ this->n=dt.n;}
    friend istream& operator>>(istream& os, $& dt);
    friend ostream& operator<<(ostream& os, const $& dt);
    bool operator == (const $& dt) const{ return (n==dt.n); }
    bool operator != (const $& dt) const{ return !(n==dt.n); }
    bool operator = (const $& dt) { n=dt.n; return true; }
    $ operator * (const $& dt){ return $((n*dt.n)%mod); }
    $ operator / (const $& dt){ return $((n*ei(dt.n))%mod); }
    $ operator + (const $& dt){ return $((n+dt.n)%mod); }
    $ operator - (const $& dt){ return $((n-dt.n + mod)%mod); }
    $ operator ^ (const $& dt){ return $(lift(n,dt.n)); }
};
istream& operator>>(istream& os, $& dt){ os >> dt.n; return os; }
ostream& operator<<(ostream& os, $& dt){ os << dt.n; return os; }

bool notprime[N]={false};
vll primes;
// ll minpdiv[N];

void soe(){
    for(ll i=2; i<N; i++){
        if(!notprime[i]){
            primes.pb(i);
            // cout<< i<< endl;
            // minpdiv[i]=i;
            for(long long j=(long long)i*(long long)i; j<(long long)N; j+=i){
                // if(!notprime[j]) minpdiv[j]=i;
                notprime[j]=true;
            }
        }
    }
    return;
}

// vll divpath(ll n){
//     vll path;
//     while(n>1){
//         path.push_back(minpdiv[n]);
//         n/=minpdiv[n];
//     }
//     if(path.size()>1) sort(path.begin(),path.end());
//     return path;
// }

// vector<pll> eulerform(ll n){
//     vll path=divpath(n);
//     vector<pll> euler;
//     if(path.size()==0) return euler;
//     ll j=1;
//     for(ll i=1; i<path.size(); i++){
//         if(path[i]!=path[i-1]){
//             euler.push_back(mp(path[i-1],j));
//             j=1;
//         }
//         else j++;
//     }
//     euler.push_back(mp(path[path.size()-1],j));
//     return euler;
// }
// ll noofdiv(ll n){
//     ll ans=1;
//     vll path=divpath(n);
//     if(path.size()==0) return 1;
//     ll j=1;
//     for(ll i=1; i<path.size(); i++){
//         if(path[i]!=path[i-1]){
//             ans*=(j+1);
//             j=1;
//         }
//         else j++;
//     }
//     ans*=(j+1);
//     return ans;
// }

// vll pfs(ll n){
//     vll p;
//     for(ll i=2; i*i<=n; i++){
//         if(n%i==0){
//             p.push_back(i);
//             while(n%i==0) n/=i;
//         }
//     }
//     if(n>1) p.push_back(n);
//     return p;
// }
// ll truephi(ll n, vll p){
//     ll m=p.size();
//     ll h=1<<m;
//     ll ans=n;
//     //double a1=log(n), a2;
//     for(ll i=0; i<h; i++){
//         ll o=0, d=1, g=1;
//         //a2=0;
//         for(ll j=0; j<m; j++){
//             if((i&g)!=0){
//                 o++;
//                 d*=p[j];
//             }
//             g+=g;
//         }
//     (o%2==1)? ans+=(n/d) : ans-=(n/d);
//     }
//     return ans;
// }
// //totient values of all numbers in almost O(n):

// ll phi[N];
// void findphi(){
//     for(ll i=0; i<N; i++) phi[i]=i;
//     for(ll i=2; i<N; i++){
//         if(phi[i]==i){
//             for(ll j=1; j*i<N; j++){
//           phi[j*i] = (phi[j*i]/i)*(i-1);
//             }
//         }
//     }
//     phi[0]=0;
//     phi[1]=0;
//     for(ll i=1; i<N; i++){
//         phi[i]=phi[i]*phi[i] + phi[i-1];
//     }
//     return ; 
// }
 
int main(){
    // fastio
    // test 
        solve();
}


