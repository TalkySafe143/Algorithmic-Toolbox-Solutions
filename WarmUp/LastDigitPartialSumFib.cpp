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


ll mo = 10;

ll modularMul(ll a, ll b) {
	return (((a%mo)*(b%mo))%mo);
}

ll modularSum(ll a, ll b) {
	return (((a%mo)+(b%mo))%mo);
}


struct matrix {
    long long mat[2][2];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
              c.mat[i][j] = 0;
              for (int k = 0; k < 2; k++) {
                  c.mat[i][j] = modularSum(c.mat[i][j], modularMul(a.mat[i][k], b.mat[k][j]));
              }
          }
        }
        return c;
    }
};

matrix matpow(matrix base, ll n) {
    matrix ans{ {
      {1, 0},
      {0, 1}
    } };
    while (n) {
        if(n&1)
            ans = ans*base;
        base = base*base;
        n >>= 1;
    }
    return ans;
}

ll fib(ll n) {
	matrix base{ {
      {1, 1},
      {1, 0}
    } };
    if (n < 0) return 0;
    if (n <= 1) return n;
    return matpow(base, n).mat[0][1];
}

ll sumFib(ll n) {
	if (n <= 0) return 0;
	ll res = modularSum(fib(n)*2, fib(n-1)) - 1;
	if (res == -1) res = 9;
	return res;
}

void solve() {
	ll m, n;
	cin >> m >> n;
	ll res = sumFib(n)-sumFib(m-1);
	if (res < 0) res += 10;
	cout << res << endl;
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