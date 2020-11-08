#include <bits/stdc++.h>
using namespace std;

long long m = 1, b = 1, x, y, maxBananas;

inline long long sumn(long long a, long long c) {
  return ((a * (a + 1)) / 2) * (c + 1) + ((c * (c + 1)) / 2) * (a + 1);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> m >> b;
  // x(0) = b, y(0) = b * m
  for (y = b; y >= 0; --y) {
    x = (b - y) * m;
    //cout << x << " " << y << " " << sumn(x, y) << endl;
    maxBananas = max(maxBananas, sumn(x, y));
  }
  cout << maxBananas << endl;
  return 0;
}
