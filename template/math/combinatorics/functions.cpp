ll inv[55];

ll binpow(ll a, ll b){
    b = (b+mod-1)%(mod-1);
    a%=mod;
    if(b==0) return 1;
    ll k = binpow(a,b/2);
    k*=k; k%=mod;
    if(b%2==1) k*=a;
    return k%mod;
}

ll combination(ll n, ll r)
{
    if (r > n) return 0;
    if (n - r < r) r = n - r;
    n %= mod;
    ll ans = 1;
    for (ll i = 0; i < r; i++){
        ans = (ans * (n - i)) % mod;
        ans = (ans * inv[i + 1]) % mod;
    }
    return ans;
}

void pre(){
    for (int i = 1; i <= 50; i++) inv[i] = binpow(i, -1);
}