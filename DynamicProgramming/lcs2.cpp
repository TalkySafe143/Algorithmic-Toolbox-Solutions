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

int longestCommonSubsequence(vector<ll> a, vector<ll> b) {
  int n = len(a), m = len(b);
  vector< vector<int> >dp(n+1, vector<int>(m+1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i-1] == b[j-1]) {
        dp[i][j] = dp[i-1][j-1]+1;
      }
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  
  // forn (i, n+1) {
  //   forn(j, m+1) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return dp[n][m];
}

vector<ll> permutation;
int ans = -1;

void search(int y, vector<ll>&a, vector<ll>&b) {
  if (y == len(a)) {
    stack<ll> r;
    r.push(-1);
    for (int i = len(permutation)-1; i >= 0; i--) r.push(permutation[i]);
    for (auto t: b) {
      if (t == r.top()) r.pop();
    }

    if (len(r) == 1) {
      ans = max(ans, len(permutation));
    }
  } else {
    permutation.push_back(a[y]);
    search(y+1, a, b);
    permutation.pop_back();
    search(y+1, a, b);
  }
}

int naiveLCS(vector<ll> a, vector<ll> b) {
  permutation.clear();
  ans = -1;
  search(0, a, b);
  return ans;
}

 
int main()
{
  fast;
  srand(time(NULL));
  
  // int w; cin >> w;
  // while (w--) {
  //   int n = rand() % 10;
  //   int m = rand() % 10;
  //   vector<ll> r, u;
  //   forn(i, n) r.push_back(rand()%15);
  //   forn(i, m) u.push_back(rand()%15);

  //   int correct = naiveLCS(r, u);
  //   int op = longestCommonSubsequence(r, u);

  //   if (correct != op) {
  //     cout << "WA\n";
  //     cout << n << endl;
  //     for (auto p: r) cout << p << " ";
  //     cout << endl;
  //     cout << m << endl;
  //     for (auto p: u) cout << p << " ";
  //     cout << endl;
  //     cout << "DIFFER: " << correct << " correct != " << op << " given\n";
  //     return 0;
  //   }
  // }
  // cout << "All test passed\n";

  int n, m; cin >> n;
  vector<ll> a(n); forn(i, n) cin >> a[i];
  cin >> m; vector<ll> b(m); forn(i, m) cin >> b[i];

  cout << longestCommonSubsequence(a, b) << endl;
 
  return 0;
}