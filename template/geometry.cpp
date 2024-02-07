
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
    friend istream& operator>>(istream& os, point& dt);// point input
    friend ostream& operator<<(ostream& os, const point& dt);// point output
    bool operator == (const point& dt) const{ return (x==dt.x && y==dt.y); }// point equality
    bool operator != (const point& dt) const{ return !(x==dt.x && y==dt.y); }
    bool operator = (const point& dt) { x=dt.x; y=dt.y; return true; } // point assignment
    point operator + (const point& dt){ return point(x+dt.x,y+dt.y); }
    point operator - (const point& dt){ return point(x-dt.x,y-dt.y); }
    line operator ^ (const point& dt); // perpendicular bisector
    double operator *(const point& dt){ return x*dt.y+y*dt.x; } // point cross
    point operator + (const double u) { return point(x+u,y+u); }
    point operator - (const double u) { return point(x-u,y-u); }
    point operator * (const double u) { return point(x*u,y*u); }
    point operator / (const double u) { return point(x/u,y/u); }
    double operator |(const point& dt){ return sqrt((this->x-dt.x)*(this->x-dt.x)+(this->y-dt.y)*(this->y-dt.y)); } // point distance
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
    friend istream& operator>>(istream& os, line& L); //radical axis
    friend ostream& operator<<(ostream& os, const line& L);
    double getx(double Y){ return -(b*Y+c)/a; }
	double gety(double X){ return -(a*X+c)/b; }
    double side(point g){ return (g.x*a+g.y*b+c); }
	double dis(point g=origin){ return abs((a*g.x+b*g.y+c)/sqrt(a*a+b*b)); }
    line perpendicular(point p){ return line(-b,a,b*p.x-a*p.y); }
    bool operator == (const line& L) const{ line L1(*this), L2(L); return (L1.a*L2.b==L1.b*L2.a && L1.dis()==L2.dis()); } //same line
    bool operator || (const line& L) const{ line L1(*this), L2(L); return (L1.a*L2.b==L1.b*L2.a); } //parallel line
    bool operator != (const line& L) const{ return !(L==*this); }
    point operator * (const line& L) const{ line L1(*this), L2(L); double det=-L1.a*L2.b+L2.a*L1.b; return (det == 0)? point(DB_MAX, DB_MAX) : point((L2.b*L1.c - L1.b*L2.c)/det,(L1.a*L2.c - L2.a*L1.c)/det); } //intersection point
    pair<line,line> operator ^ (const line& L) const{ line L1(*this), L2(L); double r1 = sqrt(L1.a*L1.a + L1.b*L1.b), r2 = sqrt(L2.a*L2.a + L2.b*L2.b); //angle bisector pair
                                                        return mp(line(r2*L1.a+r1*L2.a,r2*L1.b+r1*L2.b,r2*L1.c+r1*L2.c),line(r2*L1.a-r1*L2.a,r2*L1.b-r1*L2.b,r2*L1.c-r1*L2.c)); }
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
    double inside(point p){
        return abs(abs(area())
                  -abs(triangle(a,b,p).area())
                  -abs(triangle(b,c,p).area())
                  -abs(triangle(c,a,p).area()))<=0.0001;
    }
    //clockwise = negative
};

point start;
bool compPoint(point a, point b){
    if(triangle(start,a,b).area()==0) return ((start|a)<(start|b));
    return (triangle(start,a,b).area()>0);
}
bool compLast(point a, point b){ return (start|a)>=(start|b); }


class polygon{
    private:
    public:
    vector<point> p;
    polygon(vector<point> p = vector<point>(0)):p(p){}
    polygon(const polygon& P){ this->p=P.p; }
    friend istream& operator>>(istream& os, polygon& P);// polygon input
    friend ostream& operator<<(ostream& os, const polygon& P);
    double area(){
        double up=0, down=0; 
        ll n = p.size();
        for(ll i=0; i<n; i++){ up+=p[i].x*p[(i+1)%n].y; down+=p[i].y*p[(i+1)%n].x; }
        return (up-down)/2;
    }
    polygon hull(bool pure = true){
        ll n = p.size();
        point q[n+1];
        for(ll i=0; i<n; i++) q[i] = p[i];
        point far(INT_MAX,INT_MAX);
        ll leftdown=0;
        for(ll i=0; i<n; i++){
            if(q[i].x<far.x || (q[i].x==far.x && q[i].y<=far.y)){
                far = q[i];
                leftdown = i;
            }
        }
        swap(q[leftdown],q[0]);
        q[n]=q[0];
        start = q[0];
        sort(q+1,q+n,compPoint);
        if(!pure){
            ll g = n-1;
            while(triangle(q[n],q[n-1],q[g]).area()==0) g--;
            g++;
            for(ll i=g; i<=(g+n-1)/2; i++){
                swap(q[i],q[n-1-i+g]);
            }
        }
        ll a0 = 0, a1 = 1, a2 = 2;
        vector<point> ans;
        while(a1<n){
            double tm = triangle(q[a0],q[a1],q[a2]).area();
            if((tm>0 && pure)||(tm>=0 && !pure)){
                ans.pb(q[a0]);
                a0 = a1;
            }
            a1 = a2;
            a2++;
        }
        ans.pb(q[a0]);
        return polygon(ans);    
    }
    polygon convexHull(){
        return hull().hull().hull();
    }
    double inside(point a){
        ll n = p.size();
        if(triangle(p[0],p[1],p[n-1]).area()*triangle(p[0],p[1],a).area()<0 || 
           triangle(p[0],p[n-1],p[1]).area()*triangle(p[0],p[n-1],a).area()<0){
            return -1;
           }
        ll l = 1, r = n-1;
        while(r-l>1){
            ll m1 = (l+r)/2;
            ll m2 = m1+1;
            double f1 = triangle(p[0],p[m1],a).area();
            double f2 = triangle(p[0],p[m2],a).area();
            if(f1*f2<=0){
                l = m1;
                r = m2;
            }
            else if(f1>0) l = m2;
            else if(f1<0) r = m1;
        }
        return 
    }
};

istream& operator>>(istream& os, polygon& P){ 
    // cout<< "No. of points: ";
    ll n; os>> n;
    // cout<< "Insert points:\n";
    for(ll i=0; i<n; i++){
        point p; os>> p;
        P.p.pb(p);
    }
    return os; 
}

ostream& operator<<(ostream& os, const polygon& P){
    cout<< P.p.size()<< endl; 
    for(ll i=0; i<P.p.size(); i++){
        os<< P.p[i].x<< " "<< P.p[i].y<< "\n";
    }
    return os; 
}


// polygon
// plane
// vector
// rotating calipers
// minkowsky sum


void solve(){
    polygon Nigger; cin>> Nigger;
    cout<< Nigger.convexHull();
}

int main(){
    //test{
        solve();
    //}
}

/*


6
0 0
1 0
2 0
1 1
0 2
0 1

14
0 0
1 0
2 0
3 0
4 0
4 2
2 1
4 4
1 2
2 4
0 1
0 2
0 3
0 4



*/


// void convexhull(){
    //     ll n = p.size();
    //     bool* ishull=new bool[n];
    //     for(ll i=0; i<n ; i++) ishull[i]=false;

    //     point corner(DB_MAX,DB_MAX);
    //     int z;
    //     for(int i=0; i<n; i++){
    //         if((p[i].x<corner.x)||(p[i].x==corner.x && p[i].y<corner.y)){
    //             corner=p[i];
    //             z=i;
    //         }
    //     }
    //     start=p[z];
    //     swap(p[0],p[z]);
    //     sort(p.begin()+1,p.end(),compPoint);

    //     ll d=n-2;
    //     while(d>0 && triangle(start,p[d],p[d+1]).area()==0) d--;
    //     sort(p.begin()+d+1,p.end(),compLast);

    //     vector<ll> ans;
    //     ans.push_back(0);
    //     ans.push_back(1);
    //     ans.push_back(2);
    //     int v=ans.size();
    //     for(ll i=3; i<n; i++){
    //         ll a=v-2;
    //         ll b=v-1;
    //         if(triangle(p[ans[a]],p[ans[b]],p[i]).area()<=0){
    //             if(ans.size()==v) ans.push_back(i);
    //             else ans[v]=i;
    //             v++;
    //         }
    //         else{
    //             v--;
    //             i--;
    //         }
    //     }
    //     vector<point> hull(v);
    //     for(ll i=0; i<v; i++) hull[i]=p[ans[i]];
    //     p = hull;
    // }
    // void rectify(){
    //     vector<point> q;
    //     ll n = p.size();
    //     for(ll i=0; i<n; i++){
    //         ll j = (i+1)%n;
    //         if(p[i]!=p[j]) q.pb(p[i]);
    //     }
    //     p = q;
    //     q.clear();
    //     n = p.size();
    //     for(ll i=0; i<n; i++){
    //         ll j = (i+1)%n;
    //         ll k = (i+n-1)%n;
    //         if(triangle(p[i],p[j],p[k]).area()!=0) q.pb(p[i]);
    //     }
    //     p = q;
    //     if(p.size()>2 && triangle(p[0],p[1],p[2]).area()<0){
    //         for(ll i=0; i<p.size()/2; i++){
    //             swap(p[i],p[n-1-i]);
    //         }
    //     }
    // }