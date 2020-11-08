#include <bits/stdc++.h>
using namespace std;

double l = 10001, r = -10001, diff, m1, m2, a[200000], minSum, maxSum,
       minSumTot, maxSumTot, minW, w, w1, w2;
int n, it = 200;

double weakness(double x) {
  minSum = minSumTot = maxSum = maxSumTot = a[0] - x;
  for (int i = 1; i < n; ++i) {
    minSum = min(a[i] - x, minSum + a[i] - x);
    maxSum = max(a[i] - x, maxSum + a[i] - x);
    minSumTot = min(minSum, minSumTot);
    maxSumTot = max(maxSum, maxSumTot);
  }
  w = max(abs(minSumTot), abs(maxSumTot));
  return w;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    l = min(l, a[i]);
    r = max(r, a[i]);
  }

  r = max(abs(l), abs(r));
  l = -r;
  minW = min(weakness(r), weakness(l));

  while (--it) {
    m1 = (l * 2 + r) / 3;
    m2 = (l + 2 * r) / 3;
    w1 = weakness(m1);
    w2 = weakness(m2);
    // printf("l=%f m1=%f m2=%f r=%f minW=%f w1=%f w2=%f \n", l, m1, m2, r,
    // minW, w1, w2);

    if (w1 < w2) {
      minW = w1;
      r = m2;
    } else {
      minW = w2;
      l = m1;
    }
  }

  printf("%.15f\n", minW);
  return 0;
}
