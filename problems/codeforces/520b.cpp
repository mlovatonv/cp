#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
int n, m;

int calc(int a, int b) {
  //cout << a << " " << b << endl;
  if (a == b) return 0;
  if (a > b) return a - b;
  return calc(a, ceil((float)b / 2)) + b % 2 + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  cout << calc(n, m) << endl;
  return 0;
}
