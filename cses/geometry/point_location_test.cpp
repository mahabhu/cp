#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class point{
    public:
    ll x, y;
    point(ll x=0, ll y=0):x(x),y(y){}
};

void pin(point &p){
    cin>> p.x>> p.y;
}

void pout(point p){
    cout<< "("<< p.x<< ","<< p.y<< ")";
}

ll area(point a, point b, point c){
    return (a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);
}

void solve(){
    point a, b, c;
    pin(a);
    pin(b);
    pin(c);
    ll k = area(a,b,c);
    (k==0)? cout<< "TOUCH\n" : (k>0)? cout<< "LEFT\n" : cout<< "RIGHT\n";
}

int main(){
    ll t; cin>> t;
    while(t--) solve();
}