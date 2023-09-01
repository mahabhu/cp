
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

void solve(){
    string s; cin>> s;
    ll n = s.size();
    vll a(n+2,-1);
    ll m = 0;
    for(ll i=0; i<n; i++){
        a[0]=1;
        a[1]=1;
        if(s[i]=='+'){
            m++;
            if(m==1) a[m] = 1;
            else if(a[m-1]==0) a[m]=0;
            else a[m] = -1;
        }
        else if(s[i]=='-'){
            if(a[m]==1 && m-1>=0) a[m-1]=1;
            m--;
            if(m<0){
                cout<< "NO\n";
                return;
            }
        }
        else{
            if(s[i]=='1'){
                if(a[m]==0){
                    cout<< "NO\n";
                    return;
                }
                a[m]=1;
            }
            else{
                if(a[m]==1){
                    cout<< "NO\n";
                    return;
                }
                a[m]=0;
            }
        }
    }
    cout<< "YES\n";
}

int main(){
    test{
        solve();
    }
}


