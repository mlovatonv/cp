#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  if (1 < n && n < 4) {
    cout << "NO SOLUTION" << endl;
  } else if (n == 4) {
    for (int i = 2; i <= n; i += 2) cout << i << ' ';
    for (int i = 1; i <= n; i += 2) cout << i << ' ';
    cout << endl;
  } else {
    for (int i = 1; i <= n; i += 2) cout << i << ' ';
    for (int i = 2; i <= n; i += 2) cout << i << ' ';
    cout << endl;
  }
  return 0;
}
