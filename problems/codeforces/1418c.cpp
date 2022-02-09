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
  vector<int> a(n);
  rep(i, 0, n - 1) cin >> a[i];

  bool first = true;
  int i, j, ans = 0;

  for (i = 0; i < n; ++i) {
    if (a[i] == 1) break;
    first = false;
  }

  while (i < n) {
    j = i + 1;

    while (j < n) {
      if (a[j] == 0) break;
      ++j;
    }

    int ones = j - i;
    if (first) {
      ++ans;
      --ones;
      first = false;
    }
    ans += ones / 3;

    while (j < n) {
      if (a[j] == 1) break;
      ++j;
    }

    i = j;
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
