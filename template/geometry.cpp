
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

class point{
    public:
    double x, y;
    point(double x=0, double y=0):x(x),y(y){}
    friend istream& operator>>(istream& os, const point& dt);
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
    
    double dist(point a){ return sqrt((this->x-a.x)*(this->x-a.x)+(this->y-a.y)*(this->y-a.y)); }
    double dist(){ return dist(point(0,0)); }
    double angle(){ return atan2(y,x); }
    double angle(point p){ point h(p.x-this->x, p.y-this->y); return h.angle(); }
    bool between(point a, point b){ return ((a.x-x)*(x-b.x)<0 || (a.y-y)*(y-b.y)<0)? false : true; }
    double cross(point a, point b) { return (a-*this)*(b-*this); }
};
istream& operator>>(istream& os, point& dt){ os >> dt.x >> dt.y; return os; }
ostream& operator<<(ostream& os, const point& dt){ os << "("<< dt.x<< ","<< dt.y<< ")"; return os; }

void solve(){
    point p; cin>> p;
    point q; cin>> q;
    cout<< p+q<< p*7<< p.dist(q)<< " "<< p.dist()<< endl;

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
