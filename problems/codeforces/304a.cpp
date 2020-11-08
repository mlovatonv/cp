#include <bits/stdc++.h>
#define N 10005
using namespace std;

int n, cnt, x, y;
long long p[N];

int main(void) {
  cin >> n;
  for (int i = 1; i <= n; ++i) p[i] = pow(i, 2);
  for (int i = 3; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      x = p[i] + p[j];
      y = (int)sqrt(x);
      if (y * y == x && y <= n) ++cnt;
    }
  }
  cout << cnt << endl;
  return 0;
}
