
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
#define xaxis line(1,0,0)
#define yaxis line(0,1,0)

class line;
class circle;

class point{
    public:
    double x, y;
    point(double x=0, double y=0):x(x),y(y){}
    point(const point& dt){ this->x=dt.x; this->y=dt.y; }
    friend istream& operator>>(istream& os, point& dt);
    friend ostream& operator<<(ostream& os, const point& dt);
    bool operator == (const point& dt) const{ return (x==dt.x && y==dt.y); }
    bool operator != (const point& dt) const{ return !(x==dt.x && y==dt.y); }
    point operator + (const point& dt){ return point(x+dt.x,y+dt.y); }
    point operator - (const point& dt){ return point(x-dt.x,y-dt.y); }
    line operator ^ (const point& dt);
    double operator *(const point& dt){ return x*dt.y+y*dt.x; }
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
    line anglebisector(point a, point b);
};
istream& operator>>(istream& os, point& dt){ os >> dt.x >> dt.y; return os; }
ostream& operator<<(ostream& os, const point& dt){ os << "("<< dt.x<< ","<< dt.y<< ")"; return os; }

class line{
    public:
    double a, b, c;
    line(double a=0, double b=0, double c=0):a(a),b(b),c(c){}
    line(const line& L){ this->a=L.a; this->b=L.b; this->c=L.c; }
    line(point p, point q){ a = q.y - p.y; b = p.x - q.x; c = -(a * (p.x) + b * (p.y)); }
    //radical axis
    friend istream& operator>>(istream& os, line& L);
    friend ostream& operator<<(ostream& os, const line& L);
    double getx(double Y){ return -(b*Y+c)/a; }
	double gety(double X){ return -(a*X+c)/b; }
    double side(point g){ return (g.x*a+g.y*b+c); }
	double dis(point g=origin){ return abs((a*g.x+b*g.y+c)/sqrt(a*a+b*b)); }
    line perpendicular(point p){ return line(-b,a,b*p.x-a*p.y); }
    bool operator == (const line& L) const{ line L1(*this), L2(L); return (L1.a*L2.b==L1.b*L2.a && L1.dis()==L2.dis()); }
    bool operator || (const line& L) const{ line L1(*this), L2(L); return (L1.a*L2.b==L1.b*L2.a); }
    bool operator != (const line& L) const{ return !(L==*this); }
    point operator * (const line& L) const{ line L1(*this), L2(L); double det=-L1.a*L2.b+L2.a*L1.b; return (det == 0)? point(DB_MAX, DB_MAX) : point((L2.b*L1.c - L1.b*L2.c)/det,(L1.a*L2.c - L2.a*L1.c)/det); }
    pair<line,line> operator ^ (const line& L) const{ line L1(*this), L2(L); double r1 = sqrt(L1.a*L1.a + L1.b*L1.b), r2 = sqrt(L2.a*L2.a + L2.b*L2.b);
                                                        return mp(line(r2*L1.a+r1*L2.a,r2*L1.b+r1*L2.b,r2*L1.c+r1*L2.c),line(r2*L1.a-r1*L2.a,r2*L1.b-r1*L2.b,r2*L1.c-r1*L2.c));
                                                    }
    // angle bisector
    // angle between
    // circle intersection
    // 

};
istream& operator>>(istream& os, line& L){ os >> L.a >> L.b>> L.c; return os; }
ostream& operator<<(ostream& os, const line& L){ os << "("<< L.a<< "x + "<< L.b<< "y + "<<  L.c<< " = 0)"; return os; }

class circle{
    public:
    point c;
    double r;
    circle(point c=origin, double r=1):c(c),r(r){}
    circle(const circle& C){ this->c=C.c; this->r=C.r; }
    line operator |(const circle& C){ circle C1(*this), C2(C); return line(2*C1.c.x-2*C2.c.x, 2*C1.c.y-2*C2.c.y, C2.c.x*C2.c.x-C1.c.x*C1.c.x+C2.c.y*C2.c.y-C1.c.y*C1.c.y+C1.r*C1.r-C2.r*C2.r); }
};
line point:: operator ^ (const point& dt){ point p(*this), q(dt); return circle(p,0)|circle(q,0); }
line point::anglebisector(point a, point b){
    point c(*this);
    pair<line,line> P = line(c,a)^line(c,b);
    return (P.second.side(a)*P.second.side(b)>0)? P.first : P.second;
}
class triangle{
    public:
    point a, b, c;
    triangle(point a=origin, point b=origin, point c=origin):a(a),b(b),c(c){}
    triangle(const triangle& L){ this->a=L.a; this->b=L.b; this->c=L.c; }
    point centroid(){ return point((a.x+b.x+c.x)/3,(a.y+b.y+c.y)/3); }
    point circumcenter(){ return (a^b)*(b^c); }
    point incenter(){ return a.anglebisector(b,c)*b.anglebisector(a,c); }
    point orthocenter(){ return line(b,c).perpendicular(a)*line(a,c).perpendicular(b); }
    double area(){ return ((a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x))/2; }
};



// polygon
// plane
// vector
// rotating calipers
// minkowsky sum

void solve(){
    point p, q, r; cin>> p>> q>> r;
    cout<< triangle(p,q,r).circumcenter()<< endl;
    cout<< triangle(p,q,r).incenter()<< endl;
    cout<< triangle(p,q,r).orthocenter()<< endl;
    cout<< triangle(p,q,r).centroid()<< endl;
    cout<< triangle(p,q,r).area()<< endl;
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
