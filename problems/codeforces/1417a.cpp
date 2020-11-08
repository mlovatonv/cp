#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int t, n;
long long a[N], k, cnt;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> t;
  while (t--) {
    cnt = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i < n; ++i) {
      while (a[0] + a[i] <= k) {
        a[i] += a[0];
        ++cnt;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
