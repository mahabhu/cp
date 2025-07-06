#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll n; cin>> n;
    cout<< n<< " ";
    while(n>1){
        n = (n%2)? n*3+1 : n/2;
        cout<< n<< " ";
    }
    cout<< endl;
}

int main(){
    solve();
}