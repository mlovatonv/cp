#include <bits/stdc++.h>
using namespace std;

vector<long> v;
int i;
long n, s = 0, st = 0, m;

void r(int l) {
  if (l == v.size()) {
    m = min(m, abs(2 * s - st));
    return;
  }
  r(l + 1);
  s += v[l];
  r(l + 1);
  s -= v[l];
}

int main() {
  cin >> n;
  while (cin >> n) {
    v.push_back(n);
    st += n;
  }
  r(0);
  cout << m << endl;
  return 0;
}
