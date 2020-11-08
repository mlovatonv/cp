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

const int N = 5005;
int n, k;
int a[N], color[N], cnt[N];

void solve() {
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  int maxCnt = 0;
  rep(i, n) {
    //cout << n << ' ' << i << ' ' << a[i] << ' ' << maxCnt << endl;
    if ((maxCnt + n - i) == k) color[i] = ++maxCnt;
    else {
      int ai = a[i], ci = ++cnt[ai];
      if (ci > k) {
        cout << "NO" << endl;
        return;
      }
      color[i] = ci;
      maxCnt = max(maxCnt, ci);
    }
  }
  cout << "YES" << endl;
  rep(i, n) cout << color[i] << ' ';
  cout << endl;
}

int main() {
  fastio;
  solve();
  return 0;
}
