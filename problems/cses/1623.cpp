#include <bits/stdc++.h>
using namespace std;

vector<long> v, x;
int s, i;
long n, d, m = INT_MAX;

void r(int l) {
  if (l == s) {
    d = 0;
    for (i = 0; i < s; ++i) {
      if (x[i])
        d += v[i];
      else
        d -= v[i];
    }
    d = abs(d);
    if (d < m) {
      m = d;
    }
    return;
  }
  x[l] = 1;
  r(l + 1);
  x[l] = 0;
  r(l + 1);
}

int main() {
  cin >> n;
  while (cin >> n) v.push_back(n);
  s = v.size();
  x.resize(s);
  r(0);
  cout << m << endl;
  return 0;
}
