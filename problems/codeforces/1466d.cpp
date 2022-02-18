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
  vector<ll> w(n);
  ll acc = 0;
  rep(i, 0, n - 1) {
    cin >> w[i];
    acc += w[i];
  }
  vector<vector<int>> adj(n);
  rep(i, 0, n - 2) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].pb(v - 1);
    adj[v - 1].pb(u - 1);
  }
  vector<int> d(n);  // degree

  function<void(int, int)> dfs = [&](int v, int p) {
    ret(u, adj[v]) {
      ++d[v];
      if (u != p) {
        dfs(u, v);
      }
    }
  };

  dfs(0, -1);

  vector<pair<ll, int>> sw;
  rep(i, 0, n - 1) {
    if (d[i] >= 2) {
      sw.pb({w[i], i});
    }
  }
  sort(all(sw));

  vector<ll> ans{acc};
  rep(i, 2, n - 1) {
    if (len(sw) == 0 || (len(sw) == 1 && d[sw.back().se] == 1)) {
      ans.pb(acc);
      continue;
    }

    if (d[sw.back().se] == 1) {
      sw.pop_back();
    }

    acc += sw.back().fi;
    --d[sw.back().se];

    ans.pb(acc);
  }

  ret(a, ans) cout << a << " ";
  cout << endl;
}

int main() {
  fastio;
  int t;
  cin >> t;
  rep(i, 1, t) solve();
  return 0;
}
