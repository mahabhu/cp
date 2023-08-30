
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
#define pi acos(-1.0)
#define mod 1000000007

void solve(){
    ll n, a, d; cin>> n>> a>> d;
    ll p=a, mx = a;
    for(ll i=0; i<d; i++){
        char f; 
        cin>> f;
        if(f=='+'){
            p++;
            a++;
            mx = max(mx, a);
        }
        else{
            a--;
        }
    }
    if(p<n) cout<< "NO\n";
    else if(mx>=n) cout<< "YES\n";
    else cout<< "MAYBE\n";
}

int main(){
    test{
        solve();
    }
}


/*
11
0 1
1 2
2 3
2 4
2 5
3 6
4 7
5 8
5 9
5 10
*/
