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
    point a, b, c, d; 
    pin(a);
    pin(b);
    pin(c);
    pin(d);
    line L1(a,b), L2(c,d);
    if(L1.a==L2.a && L1.b==L2.b){
        if(L1.c==L2.c){
            ll A = L1.val(a);
            ll B = L1.val(b);
            ll C = L1.val(c);
            ll D = L1.val(d);
            ((A-C)*(C-B)>=0 ||
               (A-D)*(D-B)>=0 ||
               (C-A)*(A-D)>=0 ||
               (C-B)*(B-D)>=0)? cout<< "YES\n" : cout<< "NO\n";
        }
        else cout<< "NO\n";
    }
    else{
        ll t1 = area(a,b,c);
        ll t2 = area(a,b,d);
        ll t3 = area(c,d,a);
        ll t4 = area(c,d,b);
        if(t1>0) t1 = 1; if(t1<0) t1 = -1;
        if(t2>0) t2 = 1; if(t2<0) t2 = -1;
        if(t3>0) t3 = 1; if(t3<0) t3 = -1;
        if(t4>0) t4 = 1; if(t4<0) t4 = -1;
        (t1*t2<=0 && t3*t4<=0)? cout<< "YES\n" : cout<< "NO\n";
    }

}

int main(){
    ll t; cin>> t;
    while(t--) solve();
}