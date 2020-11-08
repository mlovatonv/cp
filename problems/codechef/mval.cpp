#include <bits/stdc++.h>
#define N 100005
using namespace std;

int t, n;
long long int temp, sum;
long long int pos[N];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    cin >> n;
    int j = 0;
    sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> temp;
      if (temp >= 0) {
        pos[j] = temp;
        sum += pos[j++];
      }
    }
    if (j == 0) {
      printf("0\n0\n");
      continue;
    }
    printf("%d\n%d", sum, j);
    for (int i = 0; i < j; ++i) {
      printf(" %d", pos[i]);
    }
    printf("\n");
  }
  return 0;
}
