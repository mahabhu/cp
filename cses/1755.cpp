
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

ll lift(ll a, ll b){
    if(b==0) return 1;
    ll k = lift(a,b/2);
    k*=k; k%=mod;
    if(b%2==1) k*=a;
    return k%mod;
}

void solve(){
    string s; cin>> s;
    ll n = s.size();
    ll a[26*2]={0};
    for(ll i=0; i<n; i++){
        ll h = (s[i]-'A');
        a[h]++;
    }
    for(ll i=0; i<26; i++){
        if(a[i]%2==1){
            a[i+26]++;
            a[i]--;
        }
        a[i]/=2;
    }
    ll r = 0;
    for(ll i=0; i<2*26; i++){
        for(ll j=0; j<a[i]; j++){
            s[r]=('A'+(i%26));
            r++;
        }
    }
    for(ll i=25; i>=0; i--){
        for(ll j=0; j<a[i]; j++){
            s[r]=('A'+(i%26));
            r++;
        }
    }
    // cout<< s<< endl;
    for(ll i=0; i<n; i++){
        if(s[i]!=s[n-1-i]){
            cout<< "NO SOLUTION\n";
            return;
        }
    }
    cout<< s<< endl;
}
 
int main(){
    // test{
        solve();
    // }
}


