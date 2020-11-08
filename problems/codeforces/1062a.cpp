#include <bits/stdc++.h>
#define N 105
using namespace std;

int n, i, j, cnt, maxCnt = 1;
int a[N];

int main(void)
{
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> a[i];
  a[i] = 1001;
  for (i = 1; i <= n + 1; ++i) {
    //cout << "cnt=" << cnt << endl;
    if (a[i - 1] == a[i] - 1) {
      ++cnt;
    } else {
      maxCnt = max(maxCnt, cnt);
      cnt = 0;
    }
  }
  maxCnt = max(maxCnt, cnt);
  cout << maxCnt - 1 << endl;
  return 0;
}
