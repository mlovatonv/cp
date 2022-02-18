#define DBG_ENABLED 0
#if DBG_ENABLED
#include "dbg.h"
#else
#define dbg(x...)
#endif

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
using pli = pair<ll, int>;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  rep(i, 1, n - 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  vector<pli> d(n);
  vector<ll> l(n);

  function<ll(int, int, ll)> dfs = [&](int v, int p, ll lu) {
    l[v] = lu;
    ll ld = 0;
    ret(u, adj[v]) {
      if (u != p) {
        ld += dfs(u, v, lu + 1) + 1LL;
      }
    }
    d[v] = {ld - lu, v};
    return ld;
  };

  dfs(0, -1, 0);

  sort(all(d));

  vector<bool> x(n);  // selected
  rep(i, 0, k - 1) { x[d[i].se] = true; }

  dbg(d);

  ll ans = 0;

  function<void(int, int, int)> dfs2 = [&](int v, int p, ll nx) {
    ll mx = nx;
    if (x[v]) {
      dbg(v + 1);
      dbg(l[v] - nx);
      ans += l[v] - nx;
      ++mx;
    }
    ret(u, adj[v]) {
      if (u != p) {
        dfs2(u, v, mx);
      }
    }
  };

  dfs2(0, -1, 0);

  cout << ans << endl;
}

int main() {
  fastio;
  solve();
  return 0;
}
