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

int coinProblem(vector<int> d, int money) {
  vector<int> dp(money+1, 0);
  for (int i = 1; i <= money; i++) {
    int optimal = 1e8;
    for (auto y: d) {
      if (i-y >= 0) optimal = min(optimal, dp[i-y]+1);
    }
    dp[i] = optimal;
  }

  return dp[money];
}

void solve()
{
  int n; cin >> n;
  cout << coinProblem({1, 3, 4}, n) << endl;
}

int main()
{
  fast;

  int t = 1;
  //cin >> t;

  while (t--)
  {
    solve();
  }

  return 0;
}