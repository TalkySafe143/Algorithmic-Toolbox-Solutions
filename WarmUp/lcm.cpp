#include <bits/stdc++.h>
 
typedef long long ll;
typedef unsigned long long ull;
ll const MOD = 10e9+7;
#define endl '\n'
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pp pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornm(i, n, m) for(ll i = n; i <= m; i++)
#define rforn(i, n) for(int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define ms(x, n) memset(x, n, sizeof(x))
#define find(x, n) find(all(x), n) != x.end()
#define suma(a, b) ((a % MOD) + (b % MOD)) % MOD
#define resta(a, b) ((a % MOD) - (b % MOD)) % MOD
#define multi(a, b) ((a % MOD) * (b % MOD)) % MOD
//" \n"[i == n - 1]
using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return (a*b)/gcd(a, b);
}

void solve() {
	ll a, b; cin >> a >> b;
	cout << lcm(a, b) << endl;
}

int main() {
    fast
    
    int t = 1;
    //cin >> t;
    
    while (t--) {
    	solve();
    }
    
    return 0;
}