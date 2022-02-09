#include <algorithm>
#include <iostream>
#include <utility>
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
using pii = pair<int, int>;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pii> lr(m);
  rep(i, 0, m - 1) { cin >> lr[i].fi >> lr[i].se; }

  string ans(n, '0');
  for (int i = 0; i < n; i += 2) {
    ans[i] = '1';
  }

  cout << ans << endl;
}

int main() {
  fastio;
  solve();
  return 0;
}
