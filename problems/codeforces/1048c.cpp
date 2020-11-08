#include <bits/stdc++.h>
using namespace std;
using ld = long double;
int t, fi, n, l;

ld solve() {
  cin >> n >> l;
  bool f[l];
  for (int i = 0; i < n; ++i) {
    cin >> fi;
    f[fi] = true;
  }
  ld v1 = 1, v2 = 1, d1 = 0, d2 = l, ti = 1, accti = 0;
  while (d1 <= d2) {
    accti += 1;
    d1 += v1 / ti;
    d2 -= v2 / ti;
    if (f[(int)d1] && ceil(d1) == floor(d1)) ++v1;
    if (f[(int)d2] && ceil(d2) == floor(d2)) ++v2;
  }
  return accti;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cout << setprecision(15) << solve() << endl;   
  }
  return 0;
}
