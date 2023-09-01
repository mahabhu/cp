
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test int t; cin>> t; for(int tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; ll a[n]; for(ll i=0; i<n; i++) scanf("%lld",&a[i]);
#define pb push_back
#define mp make_pair
//#define x first
//#define y second
#define N 200009
#define pll pair<ll,ll>
#define vll vector<ll>
#define pi acos(-1.0)
#define mod 1000000007
#define origin point(0,0)

class point{
    public:
    double x, y;
    point(double x=0, double y=0):x(x),y(y){}
    friend istream& operator>>(istream& os, point& dt);
    friend ostream& operator<<(ostream& os, const point& dt);
    bool operator == (const point& dt) const{ return (x==dt.x && y==dt.y); }
    bool operator != (const point& dt) const{ return !(x==dt.x && y==dt.y); }
    point operator + (const point& dt) { return point(x+dt.x,y+dt.y); }
    point operator - (const point& dt) { return point(x-dt.x,y-dt.y); }
    double operator *(const point& dt) { return x*dt.y+y*dt.x; }
    point operator + (const double u) { return point(x+u,y+u); }
    point operator - (const double u) { return point(x-u,y-u); }
    point operator * (const double u) { return point(x*u,y*u); }
    point operator / (const double u) { return point(x/u,y/u); }
    double operator |(const point& dt){ return sqrt((this->x-dt.x)*(this->x-dt.x)+(this->y-dt.y)*(this->y-dt.y)); }
    double dist(){ return *this|origin; }
    double angle(){ return atan2(y,x); }
    double angle(point p){ point h(p.x-this->x, p.y-this->y); return h.angle(); }
    bool between(point a, point b){ return ((a.x-x)*(x-b.x)<0 || (a.y-y)*(y-b.y)<0)? false : true; }
    double cross(point a, point b) { return (a-*this)*(b-*this); }
};
istream& operator>>(istream& os, point& dt){ os >> dt.x >> dt.y; return os; }
ostream& operator<<(ostream& os, const point& dt){ os << "("<< dt.x<< ","<< dt.y<< ")"; return os; }

class line{
    public:
    double a, b, c;
    line(double a=0, double b=0, double c=0):a(a),b(a),c(c){}
    line(const line& L){ this->a=L.a; this->b=L.b; this->c=L.c; }
    line(point p, point q){ a = q.y - p.y; b = p.x - q.x; c = -(a * (p.x) + b * (p.y)); }
    //radical axis
    friend istream& operator>>(istream& os, line& L);
    friend ostream& operator<<(ostream& os, const line& L);
    double getx(double Y){ return -(b*Y+c)/a; }
	double gety(double X){ return -(a*X+c)/b; }
    double side(point g){ return (g.x*a+g.y*b+c); }
	double dis(point g=origin){ return abs((a*g.x+b*g.y+c)/sqrt(a*a+b*b)); }
    bool operator == (const line& L) const{ line L1(*this), L2(L); return (L1.a*L2.b==L1.b*L2.a && L1.dis()==L2.dis()); }
    bool operator || (const line& L) const{ line L1(*this), L2(L); return (L1.a*L2.b==L1.b*L2.a); }
    bool operator != (const line& L) const{ return !(L==*this); }
    point operator * (const line& L) const{ line L1(*this), L2(L); double det=-L1.a*L2.b+L2.a*L1.b; return (det == 0)? point(DB_MAX, DB_MAX) : point((L2.b*L1.c - L1.b*L2.c)/det,(L1.a*L2.c - L2.a*L1.c)/det); }
};
istream& operator>>(istream& os, line& L){ os >> L.a >> L.b>> L.c; return os; }
ostream& operator<<(ostream& os, const line& L){ os << "("<< L.a<< "x + "<< L.b<< "y + "<<  L.c<< " = 0)"; return os; }



void solve(){
    point p; cin>> p;
    cout<< (p|origin)<< endl;
}

int main(){
    test{
        solve();
    }
}


/*
11
0 1
1 2
2 3
2 4
2 5
3 6
4 7
5 8
5 9
5 10
*/
