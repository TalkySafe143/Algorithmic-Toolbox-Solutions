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
 
int op(int num) {
  vector<int> dp(num+1, 1e7), prev(num+1, -1);
  dp[1] = 0;
  prev[1] = -1;
  for (int i = 2; i <= num; i++) {
    int optimal = dp[i-1]+1;
    prev[i] = i-1;
    if (i%2 == 0 && i/2 != 0) {
      optimal = min(optimal, dp[i/2]+1);
      if (optimal == dp[i/2]+1) prev[i] = i/2;
    }
    if (i%3 == 0 && i/3 != 0) {
      optimal = min(optimal, dp[i/3]+1);
      if (optimal == dp[i/3]+1) prev[i] = i/3;
    }
    dp[i] = optimal;
  }
 
  for (int u = num; u != -1; u = prev[u]) steps.push_back(u);
  reverse(all(steps));
 
  return dp[num];
}
 
int main()
{
  fast;
  int n; cin >> n;
  cout << op(n) << endl;
  for (auto y: steps) cout << y << " ";
  cout << endl;
 
  return 0;
}