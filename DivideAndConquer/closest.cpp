// Sebastian Galindo

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
//////////////typedef pair<int, int> pi;
typedef pair<ld,ld> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
//typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define forn(i, a) for (int i=0; i<(a); i++)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define len(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define debug(x...)
#endif

using ld = long double;
const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
// For use with integers, just set eps=0 and everything remains the same
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b

struct point{
	ld x, y;
	point(): x(0), y(0){}
	point(ld x, ld y): x(x), y(y){}

	point operator+(const point & p) const{return point(x + p.x, y + p.y);}
	point operator-(const point & p) const{return point(x - p.x, y - p.y);}
	point operator*(const ld & k) const{return point(x * k, y * k);}
	point operator/(const ld & k) const{return point(x / k, y / k);}

	point operator+=(const point & p){*this = *this + p; return *this;}
	point operator-=(const point & p){*this = *this - p; return *this;}
	point operator*=(const ld & p){*this = *this * p; return *this;}
	point operator/=(const ld & p){*this = *this / p; return *this;}

	point rotate(const ld & a) const{return point(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a));}
	point perp() const{return point(-y, x);}
	ld ang() const{
		ld a = atan2l(y, x); a += le(a, 0) ? 2*pi : 0; return a;
	}
	ld dot(const point & p) const{return x * p.x + y * p.y;}
	ld cross(const point & p) const{return x * p.y - y * p.x;}
	ld norm() const{return x * x + y * y;}
	ld length() const{return sqrtl(x * x + y * y);}
    ld dist(const point &p) const {return sqrtl((ld)((x-p.x)*(x-p.x))+(ld)((y-p.y)*(y-p.y)));}
	point unit() const{return (*this) / length();}

	bool operator==(const point & p) const{return eq(x, p.x) && eq(y, p.y);}
	bool operator!=(const point & p) const{return !(*this == p);}
	bool operator<(const point & p) const{return le(x, p.x) || (eq(x, p.x) && le(y, p.y));}
	bool operator>(const point & p) const{return ge(x, p.x) || (eq(x, p.x) && ge(y, p.y));}
	bool half(const point & p) const{return le(p.cross(*this), 0) || (eq(p.cross(*this), 0) && le(p.dot(*this), 0));}
};

istream &operator>>(istream &is, point & p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point & p){return os << "(" << p.x << ", " << p.y << ")";}
void __print(point p) {cerr << '{'; __print(p.x); cerr << ", "; __print(p.y); cerr << '}';}


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

struct PointRef {
    point p;
    int indexY;
};

int searchForPoint(int l, int r, vector<PointRef> &a, ld target) {
    if (l > r) return l-1;
    int mid = l + (r-l)/2;
    if (a[mid].p.x > target) return searchForPoint(l, mid-1, a, target);
    return searchForPoint(mid+1, r, a, target);
}

ld closest(int l, int r, vector<PointRef> &a, vector<pl> &y){
    if (l>=r) return inf;
    if (l+1 == r) return a[l].p.dist(a[r].p);

    int mid = l + (r-l)/2;
    ld one = closest(l, mid, a, y), two = closest(mid+1, r, a, y);
    ld d = min(one, two);
    int indexl = searchForPoint(l, r, a, a[mid].p.x-d);
    int indexr = searchForPoint(l, r, a, a[mid].p.x+d);
    vector<point> valid;
    for (int i = max(l, indexl); i <= min(r, indexr); i++) {
        for (int j = i+1; j <= min(r, indexr) && j <= i+7; j++) {
            if (a[i].p.dist(a[j].p) > d) continue;
            ckmin(d, a[i].p.dist(a[j].p));
        }
    }
    return d;
}

void solve(){
    int n; cin >> n;
    vector<pl> x(n), y(n);
    forn(i, n) cin >> x[i].f >> y[i].f, y[i].s = i;
    sort(all(y));
    vector<PointRef> a(n);
    forn(i, n) {
        a[y[i].s].p.x = x[y[i].s].f;
        a[y[i].s].p.y = y[i].f;
        a[y[i].s].indexY = i;
    }

    sort(all(a), [](PointRef a, PointRef b){
            return a.p < b.p;
            });
    //for (auto r: a) cout << r.p.x << " " << r.p.y << " " << r.indexY << endl; cout << endl;
    cout << fixed;
    cout << setprecision(17) << closest(0, n-1, a, y) << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
    while(T--) {
        solve();
    }
 
	return 0;
}
 

