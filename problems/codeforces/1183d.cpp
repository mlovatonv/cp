#include <bits/stdc++.h>
using namespace std;

int q, n, a, maxCandies;

int solve() {
  cin >> n;
  maxCandies = 0;
  vector<int> cnt(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a;
    ++cnt[a];
  }
  sort(cnt.begin(), cnt.end(), greater<int>());
  for (int i = 0; i <= n; ++i) {
    if (cnt[i] <= 0) break;
    maxCandies += cnt[i];
    for (int j = i + 1; j <= n; ++j) {
      if (cnt[i] == cnt[j]) --cnt[j];
      else break;
    }
  }
  return maxCandies;
}

int main(void) {
  cin >> q;
  while (q--) {
    cout << solve() << endl;
  }
  return 0;
}
