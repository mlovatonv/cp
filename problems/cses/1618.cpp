#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, d, s;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  d = 5;
  while (n / d >= 1) {
    s += n / d;
    d *= 5;
  }
  cout << s << endl;
  return 0;
}
