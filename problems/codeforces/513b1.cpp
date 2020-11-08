#include <bits/stdc++.h>
#define N 10
using namespace std;

int n, m, cnt, s, maxS, minP;
int a[N];

int main(void)
{
  cin >> n >> m;
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  for (int i = 0; i < n; ++i) maxS += a[i] * (n - i);
  //cout << "maxS=" << maxS << endl;

  do {
    //cout << "array=";
    //for (int i = 0; i < n; ++i) cout << a[i] << " ";
    //cout << endl; 

    s = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        minP = n;
        for (int k = i; k <= j; ++k) {
          minP = min(minP, a[k]);
        }
        s += minP;
      }
    }
    //cout << "s=" << s << endl;
    if (s == maxS) ++cnt;
    if (cnt == m) {
      for (int i = 0; i < n; ++i) cout << a[i] << " ";
      cout << endl;
      return 0;
    }
  } while (next_permutation(a, a + n));

  return 0;
}
