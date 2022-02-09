#include <functional>
#include <iostream>
#include <vector>
using namespace std;

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define elif else if
#define rep(i, s, e) for (int i = s; i <= e; ++i)
#define rrep(i, s, e) for (int i = s; i >= e; --i)
#define ret(i, c) for (auto &i : c)
#define all(a) a.begin(), a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<string> sp(2);
  vector<vector<int>> p(2, vector<int>(n));
  rep(i, 0, 1) cin >> sp[i];
  rep(i, 0, 1) rep(j, 0, n - 1) p[i][j] = sp[i][j] - '0';

  bool ans = true;
  int next = 0;
  rep(i, 0, n - 1) {
    if ((p[next][i] > 2 && p[!next][i] <= 2) ||
        (i == n - 1 &&
         ((next == 1 && p[next][i] > 2) ||
          (next == 0 && (p[next][i] <= 2 || p[!next][i] <= 2))))) {
      ans = false;
      break;
    }
    if (p[next][i] > 2) {
      next = !next;
    }
  }

  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
  fastio;
  int t;
  cin >> t;
  rep(i, 1, t) solve();
  return 0;
}
