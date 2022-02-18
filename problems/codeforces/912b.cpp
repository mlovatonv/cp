#include <iostream>
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
  ll n, k;
  cin >> n >> k;

  if (k == 1) {
    cout << n << endl;
    return;
  }

  ll x = 1LL << 60, ans = 0;

  rep(i, 0, 60) {
    if (!(n & x) && n >= x) {
      ans += x;
    }
    x >>= 1;
  }

  ans += n;

  cout << ans << endl;
}

int main() {
  fastio;
  solve();
  return 0;
}
