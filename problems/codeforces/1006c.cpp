#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, l, r;
long long maxSum, d[N], sumD[N], sumLeft, sumRight;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  cin >> d[0];
  sumD[0] = d[0];
  for (int i = 1; i < n; ++i) {
    cin >> d[i];
    sumD[i] = sumD[i - 1] + d[i];
  }
  r = n - 2;
  while (l <= r) {
    sumLeft = sumD[l];
    sumRight = sumD[n - 1] - sumD[r];
    if (sumLeft == sumRight) {
      maxSum = max(maxSum, sumLeft);
      ++l;
      --r; 
    } else if (sumLeft < sumRight) {
      ++l;
    } else if (sumLeft > sumRight) {
      --r;
    }
  }
  cout << maxSum << endl;
  return 0;
}
