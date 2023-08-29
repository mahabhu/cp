
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
#define DB_MAX 1000000000.00
#define test int t; cin>> t; for(int tc = 1; tc<=t; tc++)
#define arrays ll n; cin>> n; int a[n]; for(ll i=0; i<n; i++) scanf("%d",&a[i]);
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define N 200009
#define pll pair<ll,ll>
#define vll vector<ll>
#define pi acos(-1.0)
#define mod 1000000007
#define fastio std::ios::sync_with_stdio(false);
#define endl "\n"
#define invalid 1000000009
//follow sabit vi, all small case

class point{
public:
    db x;
    db y;
    point(db x, db y){
        this->x=x; this->y=y;
    }
    point(){
        this->x=0; this->y=0;
    }
    db dist(point a){
        return sqrt((this->x-a.x)*(this->x-a.x)+(this->y-a.y)*(this->y-a.y));
    }
    db dist(){
        return (this->x)*(this->x)+(this->y)*(this->y);
    }
    db angle(){
        db d=sqrt(this->dist());
        db t=asin(this->y/d);
        t=abs(t);
        if(x>=0 && y>=0) return t;
        if(x<0 && y>=0) return pi-t;
        if(x>=0 && y<0) return pi+pi-t;
        return pi+t;
    }
    db angle(point p){
        point h(p.x-this->x, p.y-this->y);
        return h.angle();
    }
    friend ostream& operator<<(ostream& os, const point& dt);

    point operator +(const point& b) const { return point{x+b.x, y+b.y}; }
    point operator -(const point& b) const { return point{x-b.x, y-b.y}; }
    ll operator *(const point& b) const { return (ll) x * b.y - (ll) y * b.x; }
    void operator +=(const point& b) { x += b.x; y += b.y; }
    void operator -=(const point& b) { x -= b.x; y -= b.y; }
    void operator *=(const int k) { x *= k; y *= k; }

    ll cross(const point& b, const point& c) const {
        return (b - *this) * (c - *this);
    }
    bool bet(point a, point b){
        db dx=(a.x-x)*(x-b.x);
        db dy=(a.y-y)*(y-b.y);
        return (dx<0 || dy<0)? false : true;
    }
};

ostream& operator<<(ostream& os, const point& dt)
{
    os << "("<< dt.x<< ","<< dt.y<< ")";
    return os;
}

class line{
public:
	db a;
	db b;
	db c;
	line(db a, db b, db c){
		this->a=a;
		this->b=b;
		this->c=c;
	}
	line(){
		this->a=0;
		this->b=0;
		this->c=0;
	}
	line(point P, point Q){
		a = Q.y - P.y;
		b = P.x - Q.x;
		c = -(a * (P.x) + b * (P.y));
	}
	line(db x1, db y1, db r1, db x2, db y2, db r2){
        	a=2*x1-2*x2;
        	b=2*y1-2*y2;
        	c=x2*x2-x1*x1+y2*y2-y1*y1+r1*r1-r2*r2;
    	}
	db side(point g){
       	 	return (g.x*a+g.y*b+c);
    	}
	db dis(point g){
        	return abs((a*g.x+b*g.y+c)/sqrt(a*a+b*b));
    	}
	bool equal(line L){
        	db f;
        	if(L.a!=0) f=this->a/L.a;
        	else if(L.b!=0) f=this->b/L.b;
        	else if(L.c!=0) f=this->c/L.c;
        	return ((this->a/L.a==f || (this->a==L.a && this->a==0))&&
               		(this->b/L.b==f || (this->b==L.b && this->b==0))&&
               		(this->c/L.c==f || (this->c==L.c && this->c==0)))? true : false;
    	}

    	bool parallel(line L){
        	db f;
        	if(L.a!=0) f=this->a/L.a;
        	else if(L.b!=0) f=this->b/L.b;
        	return ((this->a/L.a==f || (this->a==L.a && this->a==0))&&
               	(this->b/L.b==f || (this->b==L.b && this->b==0)))? true : false;
    	}
	point intersect(line L){
		db a1=this->a;
		db b1=this->b;
		db c1=this->c;
		db a2=L.a;
		db b2=L.b;
		db c2=L.c;
		db det=-a1*b2+a2*b1;

		if (det == 0){
			return point(DB_MAX, DB_MAX);
		}
		else{
			db x = (b2*c1 - b1*c2)/det;
			db y = (a1*c2 - a2*c1)/det;
			return point(x, y);
		}
	}
	db getx(db Y){
        return -(b*Y+c)/a;
	}
	db gety(db X){
        return -(a*X+c)/b;
	}
    friend ostream& operator<<(ostream& os, const line& dt);
    bool operator==(const line& dt){
        point o(0,0);
        line L1(this->a,this->b,this->c);
        line L2(dt.a,dt.b,dt.c);
        return (L1.a*L2.b==L1.b*L2.a && L1.dis(o)==L2.dis(o))? true : false;
    }
};

ostream& operator<<(ostream& os, const line& dt)
{
    os << "("<< dt.a<< ","<< dt.b<< ","<< dt.c<< ")";
    return os;
}

db area(point a, point b, point c){
    return ((a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x));
}

//ofstream ofs("out.txt");
void solve(){
    ll n; double h; 
    scanf("%lld%lf", &n, &h);
    vector<point> p(n);
    for(ll i=0; i<n; i++){
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    point eye  = p[n-1];
    eye.y+=h;
    double ans = 0;
    point m = p[n-1];
    for(ll i=n-1; i>0; i--){
        //cout<< " m : "<< m<< endl;
        ll g0 = area(eye,m,p[i]);
        ll g1 = area(eye,m,p[i-1]);
        if(g0<=0 && g1<=0){
            //cout<< "yay "<< i<< endl;
            ans+=p[i].dist(p[i-1]);
        }
        else if(g0>=0 && g1<=0){
            line l1(eye,m);
            line l2(p[i],p[i-1]);
            point f = l1.intersect(l2);
            //cout<< "go "<< i<< endl;
            ans+= p[i-1].dist(f);
            //cout<< i<< " : "<< f<< endl;
        }
        if(area(eye,m,p[i-1])<=0) m = p[i-1];
    }
    printf("%.10lf\n", ans);

}

int main(){
    //fastio;
    //test{
        solve();
    //}
    //ofs.close();
}
