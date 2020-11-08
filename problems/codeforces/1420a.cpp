#include <bits/stdc++.h>
#define N 100000
using namespace std;

int t, n;
bool possible;
long long pa, a;

int main(void)
{
  cin >> t;
  while (t--) {
    cin >> n;
    possible = false;
    cin >> pa;
    for (int i = 1; i < n; ++i) {
      cin >> a;
      if (pa <= a) possible = true;
      pa = a;
    }
    if (possible) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
