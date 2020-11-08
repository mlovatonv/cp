#include <bits/stdc++.h>
#define N 1005
using namespace std;

int t, n, k, maxWi, sumWi, trips;
int W[N];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    maxWi = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &W[i]);
      maxWi = max(maxWi, W[i]);
    }
    if (maxWi > k) {
      printf("-1\n");
      continue;
    }
    sumWi = 0;
    trips = 1;
    for (int i = 0; i < n; ++i) {
      if (sumWi + W[i] > k) {
        sumWi = 0;
        ++trips;
      }
      sumWi += W[i];
    }
    printf("%d\n", trips);
  }
  return 0;
}
