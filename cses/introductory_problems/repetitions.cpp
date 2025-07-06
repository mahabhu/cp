#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    string s; cin>> s;
    ll j = 1, ans = 1;
    for(ll i=0; i<s.size(); i++){
        if(s[i-1]==s[i]) j++;
        else{
            ans = max(ans, j);
            j = 1;
        }
    }
    ans = max(ans, j);
    cout<< ans<< endl;
}

int main(){
    solve();
}