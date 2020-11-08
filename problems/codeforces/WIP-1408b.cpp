#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
int t, n, k, ai;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    set<int> a;
    for (int i = 0; i < n; ++i) {
      cin >> ai;
      a.insert(ai);
    }
    int x = a.size(), y = 0;
    if (k == x) cout << 1 << endl;
    else if (x % (k - 1)) cout << -1 << endl;
    else {
      if (a.find(0) != a.end()) --x;
      y = ceil((float)x/(k - 1));
      cout << y + 1 << endl;
    }
  }
  return 0;
}
