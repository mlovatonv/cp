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
  int n = 4;
  vector<int> v(n);
  vector<string> ans(n, "Tidak");
  int acc = 0;
  rep(i, 0, n - 1) {
    cin >> v[i];
    acc += v[i];
  }

  auto check1 = [&]() {
    rep(i, 0, 1) {
      if (v[i] == acc) {
        if (v[i] % 2 == 0) {
          ans[n - i - 1] = "Ya";
        } else {
          ans[i] = "Ya";
        }
        return true;
      }
    }
    rep(i, 2, n - 1) {
      if (v[i] == acc) {
        ans[i] = "Ya";
        return true;
      }
    }
    return false;
  };

  auto check2 = [&]() {
    if ((v[0] + v[1]) % 2 == 0) {
      if (v[0] || v[3]) {
        ans[3] = "Ya";
      }
      if (v[1] || v[2]) {
        ans[2] = "Ya";
      }
    } else {
      if (v[0] || (!v[0] && v[3])) {
        ans[0] = "Ya";
      }
      if (v[1] || (!v[1] && v[2])) {
        ans[1] = "Ya";
      }
    }
  };

  if (!check1()) check2();

  ret(j, ans) cout << j << " ";
  cout << endl;
}

int main() {
  fastio;
  int t;
  cin >> t;
  rep(i, 1, t) solve();
  return 0;
}
