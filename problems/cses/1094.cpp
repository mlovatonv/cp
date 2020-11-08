#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
long long turns;
long long x[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 1; i < n; ++i) {
    if (x[i - 1] > x[i]) {
      turns += x[i - 1] - x[i];
      x[i] += x[i - 1] - x[i];
    }
  }
  cout << turns << endl;
  return 0;
}
