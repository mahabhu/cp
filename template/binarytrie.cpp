
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test int t; cin>> t; for(int tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; ll a[n]; for(ll i=0; i<n; i++) scanf("%lld",&a[i]);
#define pb push_back
#define mp make_pair
//#define x first
//#define y second
#define N 500009
#define pll pair<ll,ll>
#define vll vector<ll>
#define pi acos(-1.0)
#define mod 1000000007


class binarytrie{
    public:
    binarytrie* a[2];
    ll n;
    binarytrie(){ // initiate empty
        n = 0;
        a[0]=nullptr;
        a[1]=nullptr;
    }
    ~binarytrie(){ // destructor
        if(a[0]) a[0]->~binarytrie();
        if(a[1]) a[1]->~binarytrie();
        a[0] = nullptr;
        a[1] = nullptr;
    }
    void add(ll m, ll i=31){ // add 1
        n++;
        if(i==-1) return;
        ll g = (m>>i)%2;
        if(!a[g]) a[g] = new binarytrie();
        a[g]->add(m,i-1);
    }
    ll find(ll m, ll i=31){
        if(i==-1) return n;
        ll g = (m>>i)%2;
        if(!a[g]) return 0;
        return a[g]->find(n,i-1);
    }
    void print(ll j=0, ll c = 0){
        for(ll i=0; i<j; i++) cout<< " ";
        cout<< c<< "\n";
        if(a[0]) a[0]->print(j+1, 0);
        if(a[1]) a[1]->print(j+1, 1);
    }
    bool remove(ll m, ll i=31){
        if(i==-1){ n--; return true; }
        ll g = (m>>i)%2;
        if(a[g] && a[g]->remove(m,i-1)){
            if(a[g]->n==0) a[g]=nullptr;
            n--; return true;
        }
        return false;
    }
    ll index(ll m, ll i=31){
        if(i==-1) return 0;
        ll g = (m>>i)%2;
        if(!a[g]) return -1;
        ll h=a[g]->index(m,i-1);
        if(h==-1) return -1;
        for(ll i=0; i<g; i++) if(a[i]) h+=a[i]->n;
        return h;
    }
    ll get(ll m, ll i=31, ll ans=0){
        if(i==-1) return ans;
        if(a[0] && m<a[0]->n) return a[0]->get(m,i-1,ans*2);
        ll g = 0; if(a[0]) g = a[0]->n;
        if(a[1] && m<n) return a[1]->get(m-g,i-1,ans*2+1);
        return -1;
    }
    ll bound(ll m, ll i=31, ll ans=0){ // <=
        if(i==-1) return ans+n;
        ll g = (m>>i)%2;
        if(!g){
            if(a[0]) return a[0]->bound(m,i-1,ans);
            else return ans;
        }
        else{
            ll g = 0;
            if(a[0]) g = a[0]->n;
            if(a[1]) return a[1]->bound(m,i-1,ans+g);
            else return ans+g;
        }
    }
};

void solve(){
    // str
}

int main(){
    
}

