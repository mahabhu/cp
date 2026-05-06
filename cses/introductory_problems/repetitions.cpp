#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    string s;
    cin >> s;
    ll n = s.size();
    ll j = 1, mx = 1;
    for(ll i=1; i<n; i++){
        if(s[i] == s[i-1]) {
            j++;
            mx = max(mx, j);
        }
        else {
            j = 1;
        }
    }
    mx = max(mx, j);
    cout << mx << "\n";
}

int main(){
    solve();
}
