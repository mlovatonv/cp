#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;
int t;
ll a, b, ma, mi;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> a >> b;
    ma = max(a, b);
    mi = min(a, b);
    if ((a + b) % 3 == 0 && (ma - mi) <= mi) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
