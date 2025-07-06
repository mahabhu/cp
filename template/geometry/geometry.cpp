
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
#define vp vector<point>
#define vll vector<ll>
#define pi acos(-1.0)
#define mod 1000000007
#define origin point(0,0)
#define xaxis line(1,0,0)
#define yaxis line(0,1,0)

class line;
class circle;

int dcmp(double x) { return abs(x) < 1e-7 ? 0 : (x<0 ? -1 : 1);}

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
    double operator |(const point& dt){ return (this->x-dt.x)*(this->x-dt.x)+(this->y-dt.y)*(this->y-dt.y); } // point distance
    double dist(){ return *this|origin; }
    double angle(){ return atan2(y,x); }
    double angle(point p){ point h(p.x-this->x, p.y-this->y); return h.angle(); }
    bool between(point a, point b){ return ((a.x-x)*(x-b.x)<0 || (a.y-y)*(y-b.y)<0)? false : true; }
    double cross(point a, point b) { return (a-*this)*(b-*this); }
    line anglebisector(point a, point b);
};
istream& operator>>(istream& os, point& dt){ os >> dt.x >> dt.y; return os; }
ostream& operator<<(ostream& os, const point& dt){ os << "("<< dt.x<< ","<< dt.y<< ")"; return os; }
double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
double dot(point a, point b) { return a.x * b.x + a.y * b.y; }

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
    bool operator == (const line& L) const{ line L1(*this), L2(L); return (L1.a*L2.b==L1.b*L2.a && L1.a*L2.c==L1.c*L2.a); } //same line
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
    bool pointInTriangle(point p) {
        return dcmp(cross(b - a, p - a)) >= 0
            && dcmp(cross(c - b, p - b)) >= 0
            && dcmp(cross(a - c, p - c)) >= 0;
    }
    bool bonac(){
        if(area()!=0) return false;
        return ((a.x-b.x)*(b.x-c.x)>=0 && (a.y-b.y)*(b.y-c.y)>=0);
    }
    //clockwise = negative
};

point start;
bool comppoint(point a, point b){
    if(triangle(start,a,b).area()==0) return ((start|a)<(start|b));
    return (triangle(start,a,b).area()>0);
}
class polygon{
    private:
    public:
    vector<point> p;
    polygon(ll n){ p.resize(n); }
    polygon(vector<point> p = vector<point>(0)):p(p){}
    polygon(stack<point> s){
        p.resize(s.size());
        for(ll i=s.size()-1; i>=0; i--){
            p[i]=s.top(); s.pop();
        }
    }
    polygon(const polygon& P){ this->p=P.p; }
    ll size(){ return p.size();}
    friend istream& operator>>(istream& os, polygon& P);// polygon input
    friend ostream& operator<<(ostream& os, const polygon& P);
    double area(){
        double up=0, down=0; 
        ll n = p.size();
        for(ll i=0; i<n; i++){ up+=p[i].x*p[(i+1)%n].y; down+=p[i].y*p[(i+1)%n].x; }
        return (up-down)/2;
    }
    polygon hull(bool pure = true){
        ll n = size();
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
        sort(q+1,q+n,comppoint);
        if(!pure){
            ll g = n;
            while(triangle(q[n],q[n-1],q[g-1]).area()==0) g--;
            for(ll i=g; i<=(g+n-1)/2; i++) swap(q[i],q[n-1-i+g]);
        }
        stack<point> ans;
        ans.push(q[0]);
        ans.push(q[1]);
        for(ll i=2; i<=n; i++){
            while(true){
                if(ans.size()==1) break;
                point edge1 = ans.top(); ans.pop();
                point edge2 = ans.top();
                double tm = triangle(edge2,edge1,q[i]).area();
                if((pure && tm>0)||(!pure && tm>=0)){
                    ans.push(edge1);
                    break;
                }
            }
            if(i<n) ans.push(q[i]);
        }
        return polygon(ans);   
    }
    ll pointInConvexPolygon(point a) {
        ll n = p.size();
        assert(n >= 3);

        int lo = 1, hi = n - 1;
        while(hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if(dcmp(cross(p[mid] - p[0], a - p[0])) > 0) lo = mid;
            else    hi = mid;
        }

        bool in = pointInTriangle(p[0], p[lo], pt[hi], p);
        if(!in) return 1;

        if(dcmp(cross(pt[lo] - pt[lo - 1], p - pt[lo - 1])) == 0) return 0;
        if(dcmp(cross(pt[hi] - pt[lo], p - pt[lo])) == 0) return 0;
        if(dcmp(cross(pt[hi] - pt[(hi + 1) % n], p - pt[(hi + 1) % n])) == 0) return 0;
        return -1;
    }
    ll inside(point a){ // 2: boundary, 1: inside, 0: outside
        ll n = size();
        if(a==p[0]) return 2;
        if(!(triangle(p[0],p[1],a).area()>=0 && triangle(p[0],p[n-1],a).area()<=0)) return 0;
        ll l = 1, r = n-1;
        while(l<r){
            ll m1 = (l+r)/2;
            ll m2 = m1+1;
            double f1 = triangle(p[0],p[m1],a).area();
            double f2 = triangle(p[0],p[m2],a).area();
            if(f1>=0 && f2<0){
                l = m1;
                r = m1;
            }
            else if(f1<0) r = m1;
            else l = m2;
        }
        if(l<n-1) cout<< a<< " "<< l<< " "<< p[l]<< p[l+1]<< p[0];
        else cout<< a<< " "<< l<< " "<< p[l]<< p[0];
        if(l<n-1 && !triangle(p[0],p[l],p[l+1]).inside(a)) return 0;
        if(l==n-1){
            return (triangle(p[0],a,p[n-1]).bonac())? 2:0;
        }
        if(l==1 && triangle(p[0],a,p[1]).bonac()) return 2;
        return (triangle(p[l],a,p[l+1]).bonac())? 2:1;
    }

};



void reorder_polygon(vector<point> & P){
    size_t pos = 0;
    for(size_t i = 1; i < P.size(); i++){
        if(P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
            pos = i;
    }
    rotate(P.begin(), P.begin() + pos, P.end());
}

struct polarComp {
    point O, dir;
    polarComp(point O = point(0, 0), point dir = point(1, 0))
        : O(O), dir(dir) {}
    bool half(point p) {
        return dcmp(cross(dir, p)) < 0 || (dcmp(cross(dir, p)) == 0 && dcmp(dot(dir, p)) > 0);
    }
    bool operator()(point p, point q) {
        return make_tuple(half(p-O), 0) < make_tuple(half(q-O), cross(p-O, q-O));
    }
};

polygon minkowski_sum(polygon A, polygon B){
    ll n = A.size(), m = B.size();
    rotate(A.p.begin(), min_element(A.p.begin(), A.p.end()), A.p.end());
    rotate(B.p.begin(), min_element(B.p.begin(), B.p.end()), B.p.end());

    A.p.push_back(A.p[0]); B.p.push_back(B.p[0]);
    for(ll i = 0; i < n; i++) A.p[i] = A.p[i+1] - A.p[i];
    for(ll i = 0; i < m; i++) B.p[i] = B.p[i+1] - B.p[i];

    polygon C(n+m+1);
    C.p[0] = A.p.back() + B.p.back();
    merge(A.p.begin(), A.p.end()-1, B.p.begin(), B.p.end()-1, C.p.begin()+1, polarComp(point(0, 0), point(0, -1)));
    for(ll i = 1; i < C.p.size(); i++) C.p[i] = C.p[i] + C.p[i-1];
    C.p.pop_back();
    return C;
}

pair< Tf, Tf >rotatingCalipersBoundingBox(const Polygon &p) {
    using Linear::distancePointLine;
    static_assert(is_same<Tf, Ti>::value);
    int n = p.size();
    int l = 1, r = 1, j = 1;
    Tf area = 1e100;
    Tf perimeter = 1e100;
    for(int i = 0; i < n; i++) {
        Point v = (p[(i+1)%n] - p[i]) / length(p[(i+1)%n] - p[i]);
        while(dcmp(dot(v, p[r%n] - p[i]) - dot(v, p[(r+1)%n] - p[i])) < 0) r++;
        while(j < r || dcmp(cross(v, p[j%n] - p[i]) - cross(v, p[(j+1)%n] - p[i])) < 0) j++;
        while(l < j || dcmp(dot(v, p[l%n] - p[i]) - dot(v, p[(l+1)%n] - p[i])) > 0) l++;
        Tf w = dot(v, p[r%n] - p[i]) - dot(v, p[l%n] - p[i]);
        Tf h = distancePointLine(p[j%n], Line(p[i], p[(i+1)%n]));
        area = min(area, w * h);
        perimeter = min(perimeter, 2 * w + 2 * h);
    }
    return make_pair(area, perimeter);
}

    // returns the left side of polygon u after cutting it by ray a->b
Polygon cutPolygon(Polygon u, Point a, Point b) {
    using Linear::lineLineIntersection;
    using Linear::onSegment;

    Polygon ret;
    int n = u.size();
    for(int i = 0; i < n; i++) {
        Point c = u[i], d = u[(i + 1) % n];
        if(dcmp(cross(b-a, c-a)) >= 0) ret.push_back(c);
        if(dcmp(cross(b-a, d-c)) != 0) {
            Point t;
            lineLineIntersection(a, b - a, c, d - c, t);
            if(onSegment(t, Segment(c, d))) ret.push_back(t);
        }
    }
    return ret;
}

// Extreme Point for a direction is the farthest point in that direction
    // also https://codeforces.com/blog/entry/48868
    // u is the direction for extremeness
// weakly tested on https://open.kattis.com/problems/fenceortho
int extremePoint(const Polygon &poly, Point u) {
    int n = (int) poly.size();
    int a = 0, b = n;
    while(b - a > 1) {
        int c = (a + b) / 2;
        if(dcmp(dot(poly[c] - poly[(c + 1) % n], u)) >= 0 && dcmp(dot(poly[c] - poly[(c - 1 + n) % n], u)) >= 0) {
            return c;
        }

        bool a_up = dcmp(dot(poly[(a + 1) % n] - poly[a], u)) >= 0;
        bool c_up = dcmp(dot(poly[(c + 1) % n] - poly[c], u)) >= 0;
        bool a_above_c = dcmp(dot(poly[a] - poly[c], u)) > 0;

        if(a_up && !c_up) b = c;
        else if(!a_up && c_up) a = c;
        else if(a_up && c_up) {
            if(a_above_c) b = c;
            else a = c;
        }
        else {
            if(!a_above_c) b = c;
            else a = c;
        }
    }

    if(dcmp(dot(poly[a] - poly[(a + 1) % n], u)) > 0 && dcmp(dot(poly[a] - poly[(a - 1 + n) % n], u)) > 0)
        return a;
    return b % n;
}

// For a convex polygon p and a line l, returns a list of segments
// of p that touch or intersect line l.
// the i'th segment is considered (p[i], p[(i + 1) modulo |p|])
// #1 If a segment is collinear with the line, only that is returned
// #2 Else if l goes through i'th point, the i'th segment is added
// Complexity: O(lg |p|)
vector<int> lineConvexPolyIntersection(const Polygon &p, Line l) {
    assert((int) p.size() >= 3);
    assert(l.a != l.b);

    int n = p.size();
    vector<int> ret;

    Point v = l.b - l.a;
    int lf = extremePoint(p, rotate90(v));
    int rt = extremePoint(p, rotate90(v) * Ti(-1));
    int olf = orient(l.a, l.b, p[lf]);
    int ort = orient(l.a, l.b, p[rt]);

    if(!olf || !ort) {
        int idx = (!olf ? lf : rt);
        if(orient(l.a, l.b, p[(idx - 1 + n) % n]) == 0)
            ret.push_back((idx - 1 + n) % n);
        else    ret.push_back(idx);
        return ret;
    }
    if(olf == ort) return ret;

    for(int i=0; i<2; ++i) {
        int lo = i ? rt : lf;
        int hi = i ? lf : rt;
        int olo = i ? ort : olf;

        while(true) {
            int gap = (hi - lo + n) % n;
            if(gap < 2) break;

            int mid = (lo + gap / 2) % n;
            int omid = orient(l.a, l.b, p[mid]);
            if(!omid) {
                lo = mid;
                break;
            }
            if(omid == olo) lo = mid;
            else hi = mid;
        }
        ret.push_back(lo);
    }
    return ret;
}

// Tested : https://toph.co/p/cover-the-points
// Calculate [ACW, CW] tangent pair from an external point
constexpr int CW = -1, ACW = 1;
bool isGood(Point u, Point v, Point Q, int dir) { return orient(Q, u, v) != -dir; }
Point better(Point u, Point v, Point Q, int dir) { return orient(Q, u, v) == dir ? u : v; }
Point pointPolyTangent(const Polygon &pt, Point Q, int dir, int lo, int hi) {
    while(hi - lo > 1) {
        int mid = (lo + hi) / 2;
        bool pvs = isGood(pt[mid], pt[mid - 1], Q, dir);
        bool nxt = isGood(pt[mid], pt[mid + 1], Q, dir);

        if(pvs && nxt) return pt[mid];
        if(!(pvs || nxt)) {
            Point p1 = pointPolyTangent(pt, Q, dir, mid + 1, hi);
            Point p2 = pointPolyTangent(pt, Q, dir, lo, mid - 1);
            return better(p1, p2, Q, dir);
        }

        if(!pvs) {
            if(orient(Q, pt[mid], pt[lo]) == dir)               hi = mid - 1;
            else if(better(pt[lo], pt[hi], Q, dir) == pt[lo])   hi = mid - 1;
            else    lo = mid + 1;
        }
        if(!nxt) {
            if(orient(Q, pt[mid], pt[lo]) == dir)               lo = mid + 1;
            else if(better(pt[lo], pt[hi], Q, dir) == pt[lo])   hi = mid - 1;
            else    lo = mid + 1;
        }
    }

    Point ret = pt[lo];
    for(int i = lo + 1; i <= hi; i++) ret = better(ret, pt[i], Q, dir);
    return ret;
}
// [ACW, CW] Tangent
pair<Point, Point> pointPolyTangents(const Polygon &pt, Point Q) {
    int n = pt.size();
    Point acw_tan = pointPolyTangent(pt, Q, ACW, 0, n - 1);
    Point cw_tan = pointPolyTangent(pt, Q, CW, 0, n - 1);
    return make_pair(acw_tan, cw_tan);
}

namespace Circular {
    // Extremely inaccurate for finding near touches
    // compute intersection of line l with circle c
    // The intersections are given in order of the ray (l.a, l.b)
    vector<Point> circleLineIntersection(Circle c, Line l) {
        static_assert(is_same<Tf, Ti>::value);
        vector<Point> ret;
        Point b = l.b - l.a, a = l.a - c.o;

        Tf A = dot(b, b), B = dot(a, b);
        Tf C = dot(a, a) - c.r * c.r, D = B*B - A*C;
        if (D < -EPS) return ret;

        ret.push_back(l.a + b * (-B - sqrt(D + EPS)) / A);
        if (D > EPS)
            ret.push_back(l.a + b * (-B + sqrt(D)) / A);
        return ret;
    }

    // signed area of intersection of circle(c.o, c.r) &&
    // triangle(c.o, s.a, s.b) [cross(a-o, b-o)/2]
    Tf circleTriangleIntersectionArea(Circle c, Segment s) {
        using Linear::distancePointSegment;
        Tf OA = length(c.o - s.a);
        Tf OB = length(c.o - s.b);

        // sector
        if(dcmp(distancePointSegment(c.o, s) - c.r) >= 0)
            return angleBetween(s.a-c.o, s.b-c.o) * (c.r * c.r) / 2.0;

        // triangle
        if(dcmp(OA - c.r) <= 0 && dcmp(OB - c.r) <= 0)
            return cross(c.o - s.b, s.a - s.b) / 2.0;

        // three part: (A, a) (a, b) (b, B)
        vector<Point> Sect = circleLineIntersection(c, s);
        return circleTriangleIntersectionArea(c, Segment(s.a, Sect[0]))
            + circleTriangleIntersectionArea(c, Segment(Sect[0], Sect[1]))
            + circleTriangleIntersectionArea(c, Segment(Sect[1], s.b));
    }

    // area of intersecion of circle(c.o, c.r) && simple polyson(p[])
    // Tested : https://codeforces.com/gym/100204/problem/F - Little Mammoth
    Tf circlePolyIntersectionArea(Circle c, Polygon p) {
        Tf res = 0;
        int n = p.size();
        for(int i = 0; i < n; ++i)
            res += circleTriangleIntersectionArea(c, Segment(p[i], p[(i + 1) % n]));
        return abs(res);
    }

    // locates circle c2 relative to c1
    // interior             (d < R - r)         ----> -2
    // interior tangents (d = R - r)         ----> -1
    // concentric        (d = 0)
    // secants             (R - r < d < R + r) ---->  0
    // exterior tangents (d = R + r)         ---->  1
    // exterior             (d > R + r)         ---->  2
    int circleCirclePosition(Circle c1, Circle c2) {
        Tf d = length(c1.o - c2.o);
        int in = dcmp(d - abs(c1.r - c2.r)), ex = dcmp(d - (c1.r + c2.r));
        return in < 0 ? -2 : in == 0 ? -1 : ex == 0 ? 1 : ex > 0 ? 2 : 0;
    }

    // compute the intersection points between two circles c1 && c2
    vector<Point> circleCircleIntersection(Circle c1, Circle c2) {
        static_assert(is_same<Tf, Ti>::value);

        vector<Point> ret;
        Tf d = length(c1.o - c2.o);
        if(dcmp(d) == 0) return ret;
        if(dcmp(c1.r + c2.r - d) < 0) return ret;
        if(dcmp(abs(c1.r - c2.r) - d) > 0) return ret;

        Point v = c2.o - c1.o;
        Tf co = (c1.r * c1.r + sqLength(v) - c2.r * c2.r) / (2 * c1.r * length(v));
        Tf si = sqrt(abs(1.0 - co * co));
        Point p1 = scale(rotatePrecise(v, co, -si), c1.r) + c1.o;
        Point p2 = scale(rotatePrecise(v, co, si), c1.r) + c1.o;

        ret.push_back(p1);
        if(p1 != p2) ret.push_back(p2);
        return ret;
    }

    // intersection area between two circles c1, c2
    Tf circleCircleIntersectionArea(Circle c1, Circle c2) {
        Point AB = c2.o - c1.o;
        Tf d = length(AB);
        if(d >= c1.r + c2.r) return 0;
        if(d + c1.r <= c2.r) return PI * c1.r * c1.r;
        if(d + c2.r <= c1.r) return PI * c2.r * c2.r;

        Tf alpha1 = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2.0 * c1.r * d));
        Tf alpha2 = acos((c2.r * c2.r + d * d - c1.r * c1.r) / (2.0 * c2.r * d));
        return c1.sector(2 * alpha1) + c2.sector(2 * alpha2);
    }

    // returns tangents from a point p to circle c
    vector<Point> pointCircleTangents(Point p, Circle c) {
        static_assert(is_same<Tf, Ti>::value);

        vector<Point> ret;
        Point u = c.o - p;
        Tf d = length(u);
        if(d < c.r) ;
        else if(dcmp(d - c.r) == 0) {
            ret = { rotate(u, PI / 2) };
        }
        else {
            Tf ang = asin(c.r / d);
            ret = { rotate(u, -ang), rotate(u, ang) };
        }
        return ret;
    }

    // returns the points on tangents that touches the circle
    vector<Point> pointCircleTangencyPoints(Point p, Circle c) {
        static_assert(is_same<Tf, Ti>::value);

        Point u = p - c.o;
        Tf d = length(u);
        if(d < c.r) return {};
        else if(dcmp(d - c.r) == 0)     return {c.o + u};
        else {
            Tf ang = acos(c.r / d);
            u = u / length(u) * c.r;
            return { c.o + rotate(u, -ang), c.o + rotate(u, ang) };
        }
    }

    // for two circles c1 && c2, returns two list of points a && b
    // such that a[i] is on c1 && b[i] is c2 && for every i
    // Line(a[i], b[i]) is a tangent to both circles
    // CAUTION: a[i] = b[i] in case they touch | -1 for c1 = c2
    int circleCircleTangencyPoints(Circle c1, Circle c2, vector<Point> &a, vector<Point> &b) {
        a.clear(), b.clear();
        int cnt = 0;
        if(dcmp(c1.r - c2.r) < 0) {
            swap(c1, c2); swap(a, b);
        }
        Tf d2 = sqLength(c1.o - c2.o);
        Tf rdif = c1.r - c2.r, rsum = c1.r + c2.r;
        if(dcmp(d2 - rdif * rdif) < 0) return 0;
        if(dcmp(d2) == 0 && dcmp(c1.r - c2.r) == 0) return -1;

        Tf base = angle(c2.o - c1.o);
        if(dcmp(d2 - rdif * rdif) == 0) {
            a.push_back(c1.point(base));
            b.push_back(c2.point(base));
            cnt++;
            return cnt;
        }

        Tf ang = acos((c1.r - c2.r) / sqrt(d2));
        a.push_back(c1.point(base + ang));
        b.push_back(c2.point(base + ang));
        cnt++;
        a.push_back(c1.point(base - ang));
        b.push_back(c2.point(base - ang));
        cnt++;

        if(dcmp(d2 - rsum * rsum) == 0) {
            a.push_back(c1.point(base));
            b.push_back(c2.point(PI + base));
            cnt++;
        }
        else if(dcmp(d2 - rsum * rsum) > 0) {
            Tf ang = acos((c1.r + c2.r) / sqrt(d2));
            a.push_back(c1.point(base + ang));
            b.push_back(c2.point(PI + base + ang));
            cnt++;
            a.push_back(c1.point(base - ang));
            b.push_back(c2.point(PI + base - ang));
            cnt++;
        }
        return cnt;
    }
}  // namespace Circular

namespace EnclosingCircle{
    // returns false if points are collinear, true otherwise
    // circle p touch each arm of triangle abc
    // circle p touch each arm of triangle abc
    bool inCircle(Point a, Point b, Point c, Circle &p) {
        using Linear::distancePointLine;
        static_assert(is_same<Tf, Ti>::value);
        if(orient(a, b, c) == 0) return false;
        Tf u = length(b - c);
        Tf v = length(c - a);
        Tf w = length(a - b);
        p.o = (a * u + b * v + c * w) / (u + v + w);
        p.r = distancePointLine(p.o, Line(a, b));
        return true;
    }

    // set of points A(x, y) such that PA : QA = rp : rq
    Circle apolloniusCircle(Point P, Point Q, Tf rp, Tf rq) {
        static_assert(is_same<Tf, Ti>::value);
        rq *= rq; rp *= rp;
        Tf a = rq - rp;
        assert(dcmp(a));
        Tf g = (rq*P.x - rp*Q.x)/a;
        Tf h = (rq*P.y - rp*Q.y)/a;
        Tf c = (rq*P.x*P.x - rp*Q.x*Q.x + rq*P.y*P.y - rp*Q.y*Q.y)/a;
        Point o(g, h);
        Tf R = sqrt(g * g + h * h - c);
        return Circle(o, R);
    }

    // returns false if points are collinear, true otherwise
    // circle p goes through points a, b && c
    bool circumCircle(Point a, Point b, Point c, Circle &p) {
        using Linear::lineLineIntersection;
        if(orient(a, b, c) == 0) return false;
        Point d = (a + b) / 2, e = (a + c) / 2;
        Point vd = rotate90(b - a), ve = rotate90(a - c);
        bool f = lineLineIntersection(d, vd, e, ve, p.o);
        if(f) p.r = length(a - p.o);
        return f;
    }

    /// finds a circle that goes through all points in p, |p| <= 3.
    Circle boundary(const vector<Point> &p) {
        Circle ret;
        int sz = p.size();
        if(sz == 0)         ret.r = 0;
        else if(sz == 1)    ret.o = p[0], ret.r = 0;
        else if(sz == 2)    ret.o = (p[0] + p[1]) / 2, ret.r = length(p[0] - p[1]) / 2;
        else if(!circumCircle(p[0], p[1], p[2], ret))    ret.r = 0;
        return ret;
    }

    /// Min circle enclosing p[fr.....n-1], with points in b
    /// on the boundary of the circle, |b| <= 3.
    Circle welzl(const vector<Point> &p, int fr, vector<Point> &b) {
        if(fr >= (int) p.size() || b.size() == 3)   return boundary(b);

        Circle c = welzl(p, fr + 1, b);
        if(!c.contains(p[fr])) {
            b.push_back(p[fr]);
            c = welzl(p, fr + 1, b);
            b.pop_back();
        }
        return c;
    }
    /// Minimum enclosing circle of p, using weizl's algo.
    /// Complexity: amortized O(n).
    Circle MEC(vector<Point> p) {
        random_shuffle(p.begin(), p.end());
        vector<Point> q;
        return welzl(p, 0, q);
    }
}


void solve(){
    polygon Nigger; cin>> Nigger;
    // cout<< Nigger.convexHull();
}

int main(){
    //test{
        solve();
    //}
}

/*
prioriy_queue<string, vector<string>, greater<string> > pq; 
// #pragma GCC target ("avx2")
// #pragma GCC opointimization ("O3")
// #pragma GCC opointimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test ll t; cin>> t; for(ll tc = 1; tc<=t; tc++)
#define arrays(x,y) ll x[y]; for(ll i=0; i<y; i++) cin>> x[i]; //scanf("%lld",&b[i]);
#define cases cout<< "Case #"<< tc<< ": ";
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define mp make_pair
#define newedge ll g,h; cin>> g>> h; v[g].pb(h); v[h].pb(g);
// #define x first
// #define y second
#define pll pair<ll,ll>
#define vpair vector<pll>
#define vll vector<ll>
#define vvll vector<vll>
#define pi acos(-1.0)
#define N 200005
#define level 20
#define mod 998244353
#define endl "\n"
#define loop(X,Y,Z) for(ll X=Y; X<Z; X++)
#define yesno cout<< "YES\n" : cout<< "NO\n";
#define arrin(X,Y) ll X[Y]; for(ll i=0; i<Y; i++) cin>> X[i];
#define inf (ll)1e18

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
    bool operator == (const point& dt) const{ return (x==dt.x && y==dt.y); }
    double operator ^(const point& dt){ return x*dt.y-y*dt.x; } // point cross
    double operator *(const point& dt){ return x*dt.x+y*dt.y; } // point dot
    double operator |(const point& dt){ return (this->x-dt.x)*(this->x-dt.x)+(this->y-dt.y)*(this->y-dt.y); } // point distance
    double dist(){ return *this|origin; }
    double angle(){ return atan2(y,x); }
    double angle(point p){ point h(p.x-this->x, p.y-this->y); return h.angle(); }
    bool between(point a, point b){ return ((a.x-x)*(x-b.x)<0 || (a.y-y)*(y-b.y)<0)? false : true; }
    double cross(point a, point b) { return (a-*this)^(b-*this); }
    line perpendicularbisector(const point& dt); // perpendicular bisector
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
    bool operator == (const line& L) const{ line L1(*this), L2(L); return (L1.a*L2.b==L1.b*L2.a && L1.a*L2.c==L1.c*L2.a); } //same line
    bool operator || (const line& L) const{ line L1(*this), L2(L); return (L1.a*L2.b==L1.b*L2.a); } //parallel line
    bool operator != (const line& L) const{ return !(L==*this); }
    point operator * (const line& L) const{ line L1(*this), L2(L); double det=-L1.a*L2.b+L2.a*L1.b; return (det == 0)? point(DB_MAX, DB_MAX) : point((L2.b*L1.c - L1.b*L2.c)/det,(L1.a*L2.c - L2.a*L1.c)/det); } //intersection point
    pair<line,line> operator ^ (const line& L) const{ line L1(*this), L2(L); double r1 = sqrt(L1.a*L1.a + L1.b*L1.b), r2 = sqrt(L2.a*L2.a + L2.b*L2.b); //angle bisector pair
                                                        return mp(line(r2*L1.a+r1*L2.a,r2*L1.b+r1*L2.b,r2*L1.c+r1*L2.c),line(r2*L1.a-r1*L2.a,r2*L1.b-r1*L2.b,r2*L1.c-r1*L2.c)); }
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
line point::perpendicularbisector(const point& dt){ 
    point p(*this), q(dt); return circle(p,0)|circle(q,0); 
}
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
    bool bonac(){
        if(area()!=0) return false;
        return ((a.x-b.x)*(b.x-c.x)>=0 && (a.y-b.y)*(b.y-c.y)>=0);
    }
    //clockwise = negative
};

point start;
bool comppoint(point a, point b){
    if(triangle(start,a,b).area()==0) return ((start|a)<(start|b));
    return (triangle(start,a,b).area()>0);
}
class polygon{
    private:
    public:
    vector<point> p;
    polygon(vector<point> p = vector<point>(0)):p(p){}
    polygon(stack<point> s){
        p.resize(s.size());
        for(ll i=s.size()-1; i>=0; i--){
            p[i]=s.top(); s.pop();
        }
    }
    polygon(const polygon& P){ this->p=P.p; }
    ll size(){ return p.size();}
    friend istream& operator>>(istream& os, polygon& P);// polygon input
    friend ostream& operator<<(ostream& os, const polygon& P);
    double area(){
        double up=0, down=0; 
        ll n = p.size();
        for(ll i=0; i<n; i++){ up+=p[i].x*p[(i+1)%n].y; down+=p[i].y*p[(i+1)%n].x; }
        return (up-down)/2;
    }
    polygon hull(bool pure = true){
        ll n = size();
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
        sort(q+1,q+n,comppoint);
        if(!pure){
            ll g = n;
            while(triangle(q[n],q[n-1],q[g-1]).area()==0) g--;
            for(ll i=g; i<=(g+n-1)/2; i++) swap(q[i],q[n-1-i+g]);
        }
        stack<point> ans;
        ans.push(q[0]);
        ans.push(q[1]);
        for(ll i=2; i<=n; i++){
            while(true){
                if(ans.size()==1) break;
                point edge1 = ans.top(); ans.pop();
                point edge2 = ans.top();
                double tm = triangle(edge2,edge1,q[i]).area();
                if((pure && tm>0)||(!pure && tm>=0)){
                    ans.push(edge1);
                    break;
                }
            }
            if(i<n) ans.push(q[i]);
        }
        return polygon(ans);   
    }
    ll inside(point a){ // 2: boundary, 1: inside, 0: outside
        ll n = size();
        if(a==p[0]) return 2;
        if(!(triangle(p[0],p[1],a).area()>=0 && triangle(p[0],p[n-1],a).area()<=0)) return 0;
        ll l = 1, r = n-1;
        while(l<r){
            ll m1 = (l+r)/2;
            ll m2 = m1+1;
            double f1 = triangle(p[0],p[m1],a).area();
            double f2 = triangle(p[0],p[m2],a).area();
            if(f1>=0 && f2<0){
                l = m1;
                r = m1;
            }
            else if(f1<0) r = m1;
            else l = m2;
        }
        if(l<n-1) cout<< a<< " "<< l<< " "<< p[l]<< p[l+1]<< p[0];
        else cout<< a<< " "<< l<< " "<< p[l]<< p[0];
        if(l<n-1 && !triangle(p[0],p[l],p[l+1]).inside(a)) return 0;
        if(l==n-1){
            return (triangle(p[0],a,p[n-1]).bonac())? 2:0;
        }
        if(l==1 && triangle(p[0],a,p[1]).bonac()) return 2;
        return (triangle(p[l],a,p[l+1]).bonac())? 2:1;
    }
};

void reorder_polygon(vector<point> & P){
    size_t pos = 0;
    for(size_t i = 1; i < P.size(); i++){
        if(P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
            pos = i;
    }
    rotate(P.begin(), P.begin() + pos, P.end());
}

polygon minkowski(vector<point> P, vector<point> Q){
    reorder_polygon(P);
    reorder_polygon(Q);
    P.push_back(P[0]);
    P.push_back(P[1]);
    Q.push_back(Q[0]);
    Q.push_back(Q[1]);
    // main part
    vector<point> result;
    size_t i = 0, j = 0;
    while(i < P.size() - 2 || j < Q.size() - 2){
        result.push_back(P[i] + Q[j]);
        auto cross = (P[i + 1] - P[i])^(Q[j + 1] - Q[j]);
        if(cross >= 0 && i < P.size() - 2)
            ++i;
        if(cross <= 0 && j < Q.size() - 2)
            ++j;
    }
    return polygon(result);
}




void solve(){
    polygon P, Q; 
    cin>> P>> Q;
    polygon R = minkowski(P.p,Q.p);
    cout<< R;

}

int main(){
    fastio
    // pre();
    // test
        solve();
    // }
}
*/