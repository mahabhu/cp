#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll n;
    scanf("%lld", &n);
    printf("%lld", n);
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
        printf(" %lld", n);
    }
    printf("\n");
}

int main(){
    solve();
}
