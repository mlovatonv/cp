#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 2;
int n, l, r;
long long minOp, s;
long long a[N];

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a, a + n);
  r = n - 1;
  while (l <= r) {
    //cout << l << " " << r << endl;
    if (s < a[l]) minOp += a[l] - s;
    else if (a[r] < s) minOp += s - a[r];
    ++l;
    --r;
  }

  cout << minOp << endl;
  return 0;
}
