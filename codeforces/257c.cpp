
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
    double x;
    double y;

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
};

double area(point a, point b, point c){
    return ((a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x));
}

bool comp(point a, point b){
    return (a.angle()<b.angle());
}


double todeg(double r){
    return 180.0*r/pi;
}

double angdiff(point a, point b){
    db B = todeg(b.angle());
    db A = todeg(a.angle());
    while(B<A) B+=360;
    return B-A;
}

//ofstream ofs("out.txt");
void solve(){
    ll n; cin>> n;
    double a[n+1];
    for(ll i=0; i<n; i++){
        double X, Y;
        cin>> X>> Y;
        a[i]=atan2(Y,X);
        //if(i==0) a[n] = a[0]+pi*2;
    }
    sort(a,a+n);
    a[n] = pi*2+a[0];
    double mx = 0;
    for(ll i=0; i<n; i++){
        ll j = (i+1)%n;
        mx = max(mx,a[i+1]-a[i]);
    }
    mx = 180.0*mx/pi;
    mx = 360-mx;
    if(n==1) mx = 0;
    printf("%.10lf\n", mx);
}

int main(){
    fastio;
    //test{
        solve();
    //}
    //ofs.close();
}
