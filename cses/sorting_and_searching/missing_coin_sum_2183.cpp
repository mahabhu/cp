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

void solve(){
    arrays;
    sort(a,a+n);
    if(a[0]!=1){
        cout<< "1\n";
        return;
    }
    ll r = 1;
    for(ll i=1; i<n; i++){
        if(a[i]>r+1){
            cout<< r+1<< endl;
            return;
        }
        r+=a[i];
    }
    cout<< r+1<< endl;
}
 
int main(){
    //fastio
    // test{
        solve();
    // }
}


