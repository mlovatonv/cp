#include <bits/stdc++.h>
using namespace std;

int t;
long long int x, y, k, s, c;

int main(void) {
  cin >> t;
  while (t--) {
    cin >> x >> y >> k;
    s = 1;
    c = 0;
    while (s < k + y * k) {
      s = s - 1 + x;
      ++c;
    }
    c += k;
    cout << c << endl;
  }
  return 0;
}
