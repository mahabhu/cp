#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class point{
    public:
    ll x, y;
    point(ll x=0, ll y=0):x(x),y(y){}
    point operator +(point &q){ return point(x+q.x,y+q.y);}
    point operator -(point &q){ return point(x-q.x,y-q.y);}
    point unit(point &q){
        ll g = __gcd(abs(x-q.x),abs(y-q.y));
        return point((q.x-x)/g,(q.y-y)/g);
    }
};

class line{
    public:
    ll a, b, c;
    line(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    line(point p, point q){
        a = p.y-q.y;
        b = q.x-p.x;
        ll g = __gcd(abs(a),abs(b));
        a/=g;
        b/=g;
        if(a<0){
            a = -a;
            b = -b;
        }
        if(a==0) b = abs(b);
        c = -(a*p.x+b*p.y);
    }
    ll val(point p){
        return b*p.x-a*p.y;
    }
};

void pin(point &p){
    cin>> p.x>> p.y;
}

void pout(point p){
    cout<< "("<< p.x<< ","<< p.y<< ")";
}

ll area(point a, point b, point c){
    ll d = (a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);
    return d;
}

ll cross(point a, point b){
    return a.x*b.y-b.x*a.y;
}

ll dot(point a, point b){
    return a.x*b.x+a.y*b.y;
}

void solve(){
    ll n; cin>> n;
    point a, b, c;
    pin(a);
    pin(b);
    ll ans = 0;
    for(ll i=0; i<n-2; i++){
        pin(c);
        ans+=(abs(area(a,b,c)));
        b = c;
    }
    cout<< ans<< endl;
}

int main(){
    solve();
}