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
#define all(x) x.rbegin(), x.rend()
#define sz(x) int(x.size())
#define ms(x, n) memset(x, n, sizeof(x))
#define find(x, n) find(all(x), n) != x.end()
#define suma(a, b) ((a % MOD) + (b % MOD)) % MOD
#define resta(a, b) ((a % MOD) - (b % MOD)) % MOD
#define multi(a, b) ((a % MOD) * (b % MOD)) % MOD
//" \n"[i == n - 1]
using namespace std;

void solve() {
	int n, W;
	cin >> n >> W;
	vector<int> v(n), w(n);
	vector<pair<double, int>> vw(n);
	forn(i, n) cin >> v[i] >> w[i];
	forn(i, n) vw[i] = {(double)((double)v[i]/(double)w[i]), i};
	sort(all(vw));
	int currW = 0, j = 0;
	double ans = 0;
	while (currW < W && j < n) {
		if (currW + w[vw[j].second] > W) {
			ans += vw[j].first*(W-currW);
			currW = W;
		} else {
			ans += v[vw[j].second];
			currW += w[vw[j].second];
		}
		j++;
	}
	cout << setprecision(4) << fixed << ans << endl;
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