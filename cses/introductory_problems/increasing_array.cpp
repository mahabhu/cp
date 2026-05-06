#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll n; cin>> n;
    ll last = 0, ans = 0;
    for(ll i=0; i<n; i++){
        ll f; cin>> f;
        if(f >= last) last = f;
        else ans += (last - f);
    }
    cout << ans << endl;
}

int main(){
    solve();
}
