#include <bits/stdc++.h>
using namespace std;

long long n, m, j, k;
bool okay = true, plusOne;

bool calc() {
  for (int i = 1; i < n; ++i) {
    j = n * i;
    k = (int)sqrt(j);
    if (k * k == j) {
      n = k;
      ++m;
      if (i != 1) plusOne = true;
      return true;
    }
  }
  return false;
}

int main(void) {
  cin >> n;
  while (calc());
  if (plusOne) ++m;
  cout << n << " " << m << endl;
  return 0;
}
