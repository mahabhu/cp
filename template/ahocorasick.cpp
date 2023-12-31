
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

class trie{
    public:
    trie* a[26];
    char c;
    ll n;
    trie(char c='.'){
        this->c = c;
        n = 0;
        for(ll i=0; i<26; i++) a[i]=nullptr;
    }
    ~trie(){
        for(ll i=0; i<26; i++){
            if(a[i]) a[i]->~trie();
            a[i] = nullptr;
        }
    }
    void add(string s, ll i=0){
        n++;
        if(s.size()==i) return;
        ll g = (s[i]-'a');
        if(!a[g]) a[g] = new trie(s[i]);
        a[g]->add(s,i+1);
    }
    ll find(string s, ll i=0){
        if(s.size()==i) return n;
        ll g = (s[i]-'a');
        if(!a[g]) return 0;
        return a[g]->find(s,i+1);
    }
    void print(ll j=0){
        for(ll i=0; i<j; i++) cout<< " ";
        cout<< c<< endl;
        for(ll i=0; i<26; i++) if(a[i]) a[i]->print(j+1);
    }
    bool remove(string s, ll i=0){
        if(s.size()==i){
            n--; return true;
        }
        ll g = (s[i]-'a');
        if(a[g] && a[g]->remove(s,i+1)){
            if(a[g]->n==0) a[g]=nullptr;
            n--; return true;
        }
        return false;
    }
    ll order(string s, ll i=0){
        if(s.size()==i) return 0;
        ll g = (s[i]-'a');
        if(!a[g]) return -1;
        ll h=a[g]->order(s,i+1);
        if(h==-1) return -1;
        for(ll i=0; i<g; i++) if(a[i]) h+=a[i]->n;
        return h;
    }
};

class binarytrie{
    public:
    binarytrie* a[2];
    bool c;
    ll n;
    binarytrie(bool c = 0){
        this->c = c;
        n = 0;
        for(ll i=0; i<2; i++) a[i]=nullptr;
    }
    ~binarytrie(){
        for(ll i=0; i<2; i++){
            if(a[i]) a[i]->~binarytrie();
            a[i] = nullptr;
        }
    }
    void add(ll m, ll i=31){
        n++;
        if(i==-1) return;
        ll g = (m>>i)%2;
        if(!a[g]) a[g] = new binarytrie(g);
        a[g]->add(m,i-1);
    }
    ll find(ll m, ll i=31){
        if(i==-1) return n;
        ll g = (m>>i)%2;
        if(!a[g]) return 0;
        return a[g]->find(n,i-1);
    }
    void print(ll j=0){
        for(ll i=0; i<j; i++) cout<< " ";
        cout<< c<< "\n";
        for(ll i=0; i<2; i++) if(a[i]) a[i]->print(j+1);
    }
    bool remove(ll m, ll i=31){
        if(i==-1){
            n--; return true;
        }
        ll g = (m>>i)%2;
        if(a[g] && a[g]->remove(m,i-1)){
            if(a[g]->n==0) a[g]=nullptr;
            n--; return true;
        }
        return false;
    }
    ll order(ll m, ll i=31){
        if(i==-1) return 0;
        ll g = (m>>i)%2;
        if(!a[g]) return -1;
        ll h=a[g]->order(m,i-1);
        if(h==-1) return -1;
        for(ll i=0; i<g; i++) if(a[i]) h+=a[i]->n;
        return h;
    }
    ll get(ll m, ll i=31, ll ans=0){
        if(i==-1) return ans;
        if(a[0] && m<a[0]->n) return a[0]->get(m,i-1,ans*2);
        ll g = 0;
        if(a[0]) g = a[0]->n;
        if(a[1] && m<n) return a[1]->get(m-g,i-1,ans*2+1);
        return -1;
    }
    ll bound(ll m, ll i=31, ll ans=0){
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
    // test{
    //     solve();
    // }
    trie lol;
    while(1){
        ll f; cin>> f;
        string s;
        cin>> s;
        if(f==1) lol.add(s);
        if(f==2) lol.remove(s);
        if(f==3) cout<< "-----" << lol.find(s)<< endl;
        if(f==4) lol.print();
    }
}

