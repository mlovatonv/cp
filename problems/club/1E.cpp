#include <bits/stdc++.h>
using namespace std;

long n, m;

long comb(long x) {
  if (x < 2) return 0;
  return (x * (x - 1)) / 2;
}

int main(void) {
  cin >> n >> m;
  cout << comb(n) + comb(m) << endl;
  return 0;
}
