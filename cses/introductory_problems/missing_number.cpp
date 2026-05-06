#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll n, f;
    cin>> n;
    ll g = (n*(n+1))/2;
    for(ll i=1; i<n; i++){
        cin>> f;
        g -= f;
    }
    cout<< g << endl;
}

int main(){
    solve();
}
