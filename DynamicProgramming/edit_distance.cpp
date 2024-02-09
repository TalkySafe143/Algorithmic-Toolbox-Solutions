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
 
vector<int> steps;
 
int editDistance(string A, string B) {
  int n = len(A), m = len(B);
  vector< vector<int> > dp(n+1, vector<int>(m+1, 0));
  forn(i, n+1) dp[i][0] = i;
  forn(j, m+1) dp[0][j] = j;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int optimal = min(dp[i-1][j]+1, dp[i][j-1]+1);
      if (A[i-1] == B[j-1]) optimal = min(optimal, dp[i-1][j-1]);
      else optimal = min(optimal, dp[i-1][j-1]+1);

      dp[i][j] = optimal;
    }
  }

  return dp[n][m];
}
 
int main()
{
  fast;
  string a, b; cin >> a >> b;
  cout << editDistance(a, b) << endl;
 
  return 0;
}