#include <bits/stdc++.h>
using namespace std;

int t, n, k;

void solve() {
  cin >> n;

  bool married[n] = {0};
  int marriedCnt = 0;
  bool taken[n] = {0};
  int takenCnt = 0;
  int g;

  for (int i = 0; i < n; ++i) {
    cin >> k;
    for (int j = 0; j < k; ++j) {
      cin >> g;
      if (!married[i] && !taken[g - 1]) {
        married[i] = true;
        ++marriedCnt;
        taken[g - 1] = true;
        ++takenCnt;
      }
    }
  }

  if (n == marriedCnt) {
    cout << "OPTIMAL" << endl;
  } else {
    cout << "IMPROVE" << endl;
    for (int i = 0; i < n; ++i) {
      if (!married[i]) {
        for (int j = 0; j < n; ++j) {
          if (!taken[j]) {
            cout << i + 1 << " " << j + 1 << endl;
            return;
          }
        }
      }
    }
  }
}

int main(void) {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
