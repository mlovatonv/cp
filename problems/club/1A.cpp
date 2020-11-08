#include <bits/stdc++.h>
using namespace std;

unsigned long long m = 1000000007, n, a = 1;

int main(void) {
  cin >> n;
  a = (a * (n - 1)) % m;
  a = (a * n) % m;
  a = a * pow(9, n - 2);
  a = a % m;
  printf("%llu\n", a);
  return 0;
}
