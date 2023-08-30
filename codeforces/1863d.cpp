
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
    ll n, m; cin>> n>> m;
    char a[n][m];
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>> a[i][j];
        }
    }
    for(ll i=0; i<n; i++){
        ll u = 0, d = 0;
        for(ll j=0; j<m; j++){
            if(a[i][j]=='U'){
                (u%2==0)? a[i][j]='W' : a[i][j]='B';
                u++;
            }
            if(a[i][j]=='D'){
                (d%2==1)? a[i][j]='W' : a[i][j]='B';
                d++;
            }
        }
        if(u%2==1 || d%2==1){
            cout<< "-1\n";
            return;
        }
    }

    for(ll j=0; j<m; j++){
        ll l = 0, r = 0;
        for(ll i=0; i<n; i++){
            if(a[i][j]=='L'){
                (l%2==0)? a[i][j]='W' : a[i][j]='B';
                l++;
            }
            if(a[i][j]=='R'){
                (r%2==1)? a[i][j]='W' : a[i][j]='B';
                r++;
            }
        }
        if(r%2==1 || l%2==1){
            cout<< "-1\n";
            return;
        }
    }

    
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cout<< a[i][j];
        }
        cout<< endl;
    }
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
