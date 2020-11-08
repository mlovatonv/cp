#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, l, r, mid;
long long a[N], b[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];

  sort(a, a + n);

  for (int i = 0; i < m; ++i) {
    cout << upper_bound(a, a + n, b[i]) - a << " ";
  }
  cout << endl;
  return 0;
}
