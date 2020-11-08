#include <bits/stdc++.h>
#define N 55
using namespace std;

long long n, diff, maxA, maxB;

int main(void) {
  cin >> n;
  maxA = n / 1234567;
  maxB = n / 123456;
  //cout << maxA << " " << maxB << endl;
  for (int a = 0; a <= maxA; ++a)
    for (int b = 0; b <= maxB; ++b) {
      diff = n - a * 1234567 - b * 123456;
      if (diff == 0 || (diff > 0 && diff % 1234 == 0)) {
        cout << "YES" << endl;
        return 0;
      }
    }

  cout << "NO" << endl;
  return 0;
}
