
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

void solve(){
    ll x, y; cin>> x>> y;
    if(x<y){
        if(y%2==1){
            cout<< y*y+1-x<< endl;
        }
        else{
            cout<< (y-1)*(y-1)+x<< endl;
        }
    }
    else{
        if(x%2==0){
            cout<< x*x+1-y<< endl;
        }
        else{
            cout<< (x-1)*(x-1)+y<< endl;
        }
    }
}

int main(){
    test{
        solve();
    }
}


