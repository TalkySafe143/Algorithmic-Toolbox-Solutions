#include <bits/stdc++.h>
 
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
 
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornm(i, n, m) for (int i = n; i <= m; i++)
#define rforn(in, n) for (int i = n - 1; i >= 0; i--)
 
#define all(x) x.begin(), x.end()
#define len(x) int(x.size())
 
#define ms(x, n) memset(x, n, sizeof(x))
 
#define find(x, n) find(all(x), n) != x.end()
 
#define suma(a, b) ((a % MOD) + (b $ MOD)) % MOD
#define resta(a, b) ((a % MOD) - (b $ MOD)) % MOD
 
//" \n"[i == n - 1]
using namespace std;

int longestCommonSubsequence3D(vector<ll> a, vector<ll> b, vector<ll> c) {
  int n = len(a), m = len(b), k = len(c);
  vector< vector< vector<int> > >dp(n+1, vector< vector<int> >(m+1, vector<int>(k+1, 0)));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int u = 1; u <= k; u++) {
        if (a[i-1] == b[j-1] && b[j-1] == c[u-1]) {
          dp[i][j][u] = dp[i-1][j-1][u-1]+1;
        } else {
          dp[i][j][u] = max(dp[i-1][j][u], max(dp[i][j][u-1], dp[i][j-1][u]));
        }
      }
    }
  }

  return dp[n][m][k];
}

 
int main()
{
  fast;
  int n, m, l; cin >> n;
  vector<ll> a(n); forn(i, n) cin >> a[i];
  cin >> m; vector<ll> b(m); forn(i, m) cin >> b[i];
  cin >> l; vector<ll> c(l); forn(i, l) cin >> c[i];

  cout << longestCommonSubsequence3D(a, b, c) << endl;
 
  return 0;
}