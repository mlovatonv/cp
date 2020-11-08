#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define arr(a, n) a, a + n
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)
#define repr(i, n) for (int i = n - 1; i >= 0; --i)
#define repv(i, k, n) for (int i = k; i < n; ++i)
#define reprv(i, k, n) for (int i = k; i >= 0; --i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

const int N = 1e5;
int t;
ll n, m;

void solve() {
  cin >> n >> m;
  if (n < m) {
    cout << 0 << endl;
    return;
  }
  ll s = 0, k = n / m;
  if (k / 10 > 0) rep1(i, 9) s += (m * i) % 10;
  s *= (k / 10);
  rep1(i, (k % 10)) s += (m * i) % 10;
  cout << s << endl;
}

int main() {
  fastio;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
