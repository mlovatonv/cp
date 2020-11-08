#include <bits/stdc++.h>
using namespace std;

int t, x, y;
long n, s;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &x, &y);
    }
    s = n;
    while (n > 5) {
      n /= 2;
      s += n;
    }
    printf("%d\n", s);
  }
  return 0;
}
