#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
const int N = 1e2 + 5;
int t, n;
int a[N], b[N], c[N], p[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    int idx = 0;
    p[idx] = a[idx];
    ++idx;
    for (; idx <= n - 2; ++idx) {
      if (a[idx] != p[idx - 1]) p[idx] = a[idx];
      else if (b[idx] != p[idx - 1]) p[idx] = b[idx];
      else if (c[idx] != p[idx - 1]) p[idx] = c[idx];
    }
    if (a[idx] != p[idx - 1] && a[idx] != p[0]) p[idx] = a[idx];
    else if (b[idx] != p[idx - 1] && b[idx] != p[0]) p[idx] = b[idx];
    else if (c[idx] != p[idx - 1] && c[idx] != p[0]) p[idx] = c[idx];
    for (int i = 0; i < n; ++i) cout << p[i] << " ";
    cout << endl;
  }
  return 0;
}
