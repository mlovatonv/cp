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
  int n, m;
  cin >> n >> m;
  vector<string> b(n);
  rep(i, 0, n - 1) cin >> b[i];

  vector<int> ans;

  function<void(int, int)> fix3 = [&](int x, int y) {
    rep(i, x, x + 1) {
      rep(j, y, y + 1) {
        if (b[i][j] == '1') {
          b[i][j] = '0';
          ans.pb(i + 1);
          ans.pb(j + 1);
        }
      }
    }
    // cout << "len3=" << len(ans) << endl;
  };

  function<void(int, int)> fix2 = [&](int x, int y) {
    int ones = 0;
    rep(i, x, x + 1) {
      rep(j, y, y + 1) {
        if (b[i][j] == '1' && ones < 1) {
          b[i][j] = '0';
          ans.pb(i + 1);
          ans.pb(j + 1);
          ++ones;
        }
        elif (b[i][j] == '0') {
          b[i][j] = '1';
          ans.pb(i + 1);
          ans.pb(j + 1);
        }
      }
    }

    // cout << "len2=" << len(ans) << endl;

    fix3(x, y);
  };

  function<void(int, int)> fix1 = [&](int x, int y) {
    int zeros = 0;
    rep(i, x, x + 1) {
      rep(j, y, y + 1) {
        if (b[i][j] == '1') {
          b[i][j] = '0';
          ans.pb(i + 1);
          ans.pb(j + 1);
        }
        elif (b[i][j] == '0' && zeros < 2) {
          b[i][j] = '1';
          ans.pb(i + 1);
          ans.pb(j + 1);
          ++zeros;
        }
      }
    }

    // cout << "len1=" << len(ans) << endl;

    fix2(x, y);
  };

  function<void(int, int)> fix4 = [&](int x, int y) {
    int ones = 0;
    rep(i, x, x + 1) {
      rep(j, y, y + 1) {
        if (b[i][j] == '1' && ones < 3) {
          b[i][j] = '0';
          ans.pb(i + 1);
          ans.pb(j + 1);
          ++ones;
        }
      }
    }

    // cout << "len4=" << len(ans) << endl;

    fix1(x, y);
  };

  function<void(int, int)> fix = [&](int x, int y) {
    int ones = 0;
    rep(i, x, x + 1) {
      rep(j, y, y + 1) {
        if (b[i][j] == '1') ++ones;
      }
    }

    if (ones == 4) fix4(x, y);
    elif (ones == 3) fix3(x, y);
    elif (ones == 2) fix2(x, y);
    elif (ones == 1) fix1(x, y);
  };

  for (int i = 0; i + 1 < n; i += 2) {
    for (int j = 0; j + 1 < m; j += 2) {
      fix(i, j);
    }
  }

  if (n % 2) {
    for (int j = 0; j + 1 < m; j += 2) {
      fix(n - 2, j);
    }
  }

  if (m % 2) {
    for (int i = 0; i + 1 < n; i += 2) {
      fix(i, m - 2);
    }
  }

  if (m % 2 && n % 2) {
    fix(n - 2, m - 2);
  }

  cout << (int)len(ans) / 6 << endl;
  // cout << "len=" << len(ans) << endl;
  rep(i, 0, (int)len(ans) - 1) {
    cout << ans[i] << " ";
    if (i % 6 == 5) cout << endl;
  }
  // cout << endl;
}

int main() {
  fastio;
  int t;
  cin >> t;
  rep(i, 1, t) solve();
  return 0;
}
