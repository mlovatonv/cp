#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
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
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(m));
  rep(i, 0, n - 1) rep(j, 0, m - 1) cin >> a[i][j];

  ll ans = 0;
  rep(i, 0, (n - 1) / 2) {
    rep(j, 0, (m - 1) / 2) {
      vector<ll> v{a[i][j]};
      if (n - i - 1 != i) {
        v.pb(a[n - i - 1][j]);
      }
      if (m - j - 1 != j) {
        v.pb(a[i][m - j - 1]);
      }
      if (n - i - 1 != i && m - j - 1 != j) {
        v.pb(a[n - i - 1][m - j - 1]);
      }
      sort(all(v));
      ret(it, v) ans += abs(v[len(v) / 2] - it);
    }
  }

  cout << ans << endl;
}

int main() {
  fastio;
  int t;
  cin >> t;
  rep(i, 1, t) solve();
  return 0;
}
