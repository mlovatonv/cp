#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define all(a) a.begin(), a.end()
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

const int N = 1e3;
int t, n;
int a[N];

void solve() {
  cin >> n;
  n *= 4;
  rep(i, n) cin >> a[i];
  sort(a, a + n);
  int area = a[0] * a[n - 1], l = 0, r = n - 1;
  while (l < r) {
    if (a[l] != a[l + 1] || a[r] != a[r - 1] || (a[l] * a[r]) != area) {
      cout << "NO" << endl;
      return;
    }
    l += 2;
    r -= 2;
  }
  cout << "YES" << endl;
}

int main() {
  fastio;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
