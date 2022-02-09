#include <cmath>
#include <iostream>
#include <vector>

//#include "../dbg.h";
using namespace std;

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define elif else if
#define ret(i, c) for (auto &i : c)
#define all(a) a.begin(), a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using ll = long long;
#define rep(i, s, e) for (ll i = s; i <= e; ++i)
#define rrep(i, s, e) for (ll i = s; i >= e; --i)

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<ll> dp(n + 1);  // number of ways to get from cell x to 1
  dp[1] = 1;

  ll acc = dp[1];
  rep(i, 2, n) {
    //dbg(i);

    ll acc2 = 0;

    ll r = sqrtl(i);
    rep(j, 2, r - 1) {
      acc2 += dp[i / j];
      acc2 %= m;
    }
    rep(j, 1, i / r) {
      ll c = (i / j) - (i / (j + 1));
      acc2 += c * dp[j];
      acc2 %= m;
    }

    // ll k = 0;  // j < k
    // for (ll j = 2; j <= i; j = k + 1) {
    //   k = i / (i / j);
    //   ll c = (k - j + 1);
    //   acc2 += c * dp[i / j];
    //   acc2 %= m;
    // }

    //dbg(acc2);

    dp[i] = (acc + acc2) % m;

    //dbg(dp[i]);

    acc = (acc + dp[i]) % m;
  }

  cout << dp[n] << endl;
}

int main() {
  fastio;
  solve();
  return 0;
}
