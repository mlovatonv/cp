#include <bits/stdc++.h>
using namespace std;

int t;
long long x, y, ma, mi, v, s;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> x >> y;
    ma = max(x, y);
    mi = min(x, y);
    v = ma % 2 == 0 ? mi == x ? -1 : 1 : mi == x ? 1 : -1;
    s = 1 + ma * (ma - 1) + v * (ma - mi);
    cout << s << endl;
  }
  return 0;
}
