
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test ll t; cin>> t; for(ll tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; ll a[n]; for(ll i=0; i<n; i++) scanf("%lld",&a[i]);
#define pb push_back
#define mp make_pair
//#define x first
//#define y second
#define N 200001
#define pll pair<ll,ll>
#define vll vector<ll>
#define pi acos(-1.0)
#define mod 1000000007


ll a[N];

struct node {
	ll sum, mx1, mx2, mxc, mn1, mn2, mnc, lz;   
    // Sum tag
	// Max value
	// Second Max value
	// Max value count
	// Min value
	// Second Min value
	// Min value count
    // Lazy tag
} tree[N * 4];

void merge(ll e) {
	// sum
	tree[e].sum = tree[e+e].sum + tree[e+e+1].sum;

	// max
	if (tree[e+e].mx1 == tree[e+e+1].mx1) {
		tree[e].mx1 = tree[e+e].mx1;
		tree[e].mx2 = max(tree[e+e].mx2, tree[e+e+1].mx2);
		tree[e].mxc = tree[e+e].mxc + tree[e+e+1].mxc;
	} else {
		if (tree[e+e].mx1 > tree[e+e+1].mx1) {
			tree[e].mx1 = tree[e+e].mx1;
			tree[e].mx2 = max(tree[e+e].mx2, tree[e+e+1].mx1);
			tree[e].mxc = tree[e+e].mxc;
		} else {
			tree[e].mx1 = tree[e+e+1].mx1;
			tree[e].mx2 = max(tree[e+e].mx1, tree[e+e+1].mx2);
			tree[e].mxc = tree[e+e+1].mxc;
		}
	}

	// min
	if (tree[e+e].mn1 == tree[e+e+1].mn1) {
		tree[e].mn1 = tree[e+e].mn1;
		tree[e].mn2 = min(tree[e+e].mn2, tree[e+e+1].mn2);
		tree[e].mnc = tree[e+e].mnc + tree[e+e+1].mnc;
	} else {
		if (tree[e+e].mn1 < tree[e+e+1].mn1) {
			tree[e].mn1 = tree[e+e].mn1;
			tree[e].mn2 = min(tree[e+e].mn2, tree[e+e+1].mn1);
			tree[e].mnc = tree[e+e].mnc;
		} else {
			tree[e].mn1 = tree[e+e+1].mn1;
			tree[e].mn2 = min(tree[e+e].mn1, tree[e+e+1].mn2);
			tree[e].mnc = tree[e+e+1].mnc;
		}
	}
}

void push_add(ll l, ll r, ll e, ll v) {
	if(v == 0) return; 
	tree[e].sum += (r-l)*v;
	tree[e].mx1 += v;
	if(tree[e].mx2 != -INT_MAX) tree[e].mx2 += v;
	tree[e].mn1 += v;
	if(tree[e].mn2 != INT_MAX) tree[e].mn2 += v;
	tree[e].lz += v;
}

// corresponds to a chmin update
void push_max(ll e, ll v, bool l) {
	if (v >= tree[e].mx1) { return; }
	tree[e].sum -= tree[e].mx1 * tree[e].mxc;
	tree[e].mx1 = v;
	tree[e].sum += tree[e].mx1 * tree[e].mxc;
	if(l)  tree[e].mn1 = tree[e].mx1;
	else{
		if(v <= tree[e].mn1) tree[e].mn1 = v; 
		else if(v < tree[e].mn2) tree[e].mn2 = v;
	}
}

// corresponds to a chmax update
void push_min(ll e, ll v, bool l) {
	if (v <= tree[e].mn1) return;
	tree[e].sum -= tree[e].mn1 * tree[e].mnc;
	tree[e].mn1 = v;
	tree[e].sum += tree[e].mn1 * tree[e].mnc;
	if(l) tree[e].mx1 = tree[e].mn1;
	else{
		if(v >= tree[e].mx1) tree[e].mx1 = v; 
		else if(v > tree[e].mx2) tree[e].mx2 = v;
	}
}

void pushdown(ll l, ll r, ll e) {
	if (r-l==1) return;
	// sum
	ll m = (l+r)/2;
	push_add(l,m,e+e,tree[e].lz);
	push_add(m,r,e+e+1,tree[e].lz);
	tree[e].lz = 0;

	// max
	push_max(e+e, tree[e].mx1, m-l==1);
	push_max(e+e+1, tree[e].mx1, r-m==1);

	// min
	push_min(e+e, tree[e].mn1, m-l==1);
	push_min(e+e+1, tree[e].mn1, r-m==1);
}

void build(ll l, ll r, ll e) {
	tree[e].lz = 0;
	if (r-l==1) {
		tree[e].sum = tree[e].mx1 = tree[e].mn1 = a[l];
		tree[e].mxc = tree[e].mnc = 1;
		tree[e].mx2 = -INT_MAX;
		tree[e].mn2 = INT_MAX;
		return;
	}

	ll m = (l + r)/2;
	build(l,m,e+e);
	build(m,r,e+e+1);
	merge(e);
}

void update_add(ll l, ll r, ll e, ll tl, ll tr, ll v) {
	if (tr <= l || r <= tl) { return; }
	if (tl <= l && r <= tr) {
		push_add(l,r,e,v);
		return;
	}
	pushdown(l, r, e);

	ll m = (l + r) >> 1;
	update_add(l,m,e+e,tl,tr,v);
	update_add(m,r,e+e+1,tl,tr,v);
	merge(e);
}

void update_chmin(ll l, ll r, ll e, ll tl, ll tr, ll v) {
	if (tr <= l || r <= tl || v >= tree[e].mx1) { return; }
	if (tl <= l && r <= tr && v > tree[e].mx2) {
		push_max(e,v,r-l==1);
		return;
	}
	pushdown(l, r, e);

	ll m = (l+r)/2;
	update_chmin(l,m,e+e,tl,tr,v);
	update_chmin(m,r,e+e+1,tl,tr,v);
	merge(e);
}

void update_chmax(ll l, ll r, ll e, ll tl, ll tr, ll v) {
	if (tr <= l || r <= tl || v <= tree[e].mn1) { return; }
	if (tl <= l && r <= tr && v < tree[e].mn2) {
		push_min(e, v, r-l==1);
		return;
	}
	pushdown(l, r, e);

	ll m = (l + r) >> 1;
	update_chmax(l,m,e+e,tl,tr,v);
	update_chmax(m,r,e+e+1,tl,tr,v);
	merge(e);
}

ll query_sum(ll l, ll r, ll e, ll tl, ll tr) {
	if (tr <= l || r <= tl) { return 0; }
	if (tl <= l && r <= tr) { return tree[e].sum; }
	pushdown(l, r, e);

	ll m = (l + r) >> 1;
	return query_sum(l,m,e+e,tl,tr)+query_sum(m,r,e+e+1,tl,tr);
}

void update_val(ll t, ll v, ll n){
	ll g = query_sum(0,n,1,t,t+1);
	update_add(0,n,1,t,t+1,v-g);
	return;
}

int main() {
	ll n, q; cin>> n>> q;

	for(ll i = 0; i < n; i++) cin >> a[i];
	build(0,n,1);
	for (ll j = 0; j < q; j++) {
		ll t;
		cin >> t;
		if (t == 0) {
			ll l, r;
			ll x;
			cin >> l >> r >> x;
			update_chmin(0,n,1,l-1,r,x);
		} else if (t == 1) {
			ll l, r;
			ll x;
			cin >> l >> r >> x;
			update_chmax(0,n,1,l-1,r,x);
		} else if (t == 2) {
			ll l, r;
			ll x;
			cin >> l >> r >> x;
			update_add(0,n,1,l-1,r,x);
		} else if (t == 3) {
			ll l, r;
			cin >> l >> r;
			cout << query_sum(0,n,1,l-1,r) << '\n';
		}
	}
}
