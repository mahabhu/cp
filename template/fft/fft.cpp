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
#define pll pair<ll,ll>
#define vpair vector<pll>
#define vll vector<ll>
#define vvll vector<vll>
#define pi acos(-1.0)
#define mod 998244353
#define endl "\n"
#define loop(X,Y,Z) for(ll X=Y; X<Z; X++)
#define yesno cout<< "YES\n" : cout<< "NO\n";
#define arrin(X,Y) ll X[Y]; for(ll i=0; i<Y; i++) cin>> X[i];

#define cd complex<double>
#define vd vector<cd>

cd unity(ll i, ll n){
    double pi2=4*acos(0);
    cd w(cos(i*pi2/n),sin(i*pi2/n));
    return w;
}
vd forwardfft(vd a){
    ll n=a.size();
    if(n==1) return a;
    cd wn=unity(1,n);
    cd w=1;
    vd a2[2];
    for(ll i=0; i<n; i++){
        a2[i%2].push_back(a[i]);
    }
    vd y2[2];
    y2[0]=forwardfft(a2[0]);
    y2[1]=forwardfft(a2[1]);
    vd y(n);
    for(ll i=0; i<n/2; i++){
        y[i]=y2[0][i]+w*y2[1][i];
        y[i+n/2]=y2[0][i]-w*y2[1][i];
        w=w*wn; }
    return y;
}
vd convolute(vd a, vd b){
    ll n=a.size();
    vd c(n);
    for(ll i=0; i<n; i++) c[i]=a[i]*b[i];
    return c;
}
vd inversefft(vd a){
    ll n=a.size();
    if(n==1) return a;
    cd wn=unity(1,n);
    cd w=1;
    vd a2[2];
    for(ll i=0; i<n; i++){
        a2[i%2].push_back(a[i]);
    }
    vd y2[2];
    y2[0]=inversefft(a2[0]);
    y2[1]=inversefft(a2[1]);
    vd y(n);
    for(ll i=0; i<n/2; i++){
        y[i]=(y2[0][i]+(w*y2[1][i]));
        y[i+n/2]=(y2[0][i]-(w*y2[1][i]));
        y[i]=y[i]/2.0;
        y[i+n/2]=y[i+n/2]/2.0;
        w=w/wn; }
    return y;
}
vd polymul(vd a, vd b){
    vd a2=forwardfft(a);
    vd b2=forwardfft(b);
    vd c=convolute(a2,b2);
    c=inversefft(c);
    return c;
}

void solve(){
}

int main(){
    fastio
    //test{
        solve();
    //}
}