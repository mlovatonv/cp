#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int n, oddIdx = -1, l, r;
int occ[26];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> s;
  n = s.size();
  char ns[n + 1];
  ns[n] = '\0';
  for (int i = 0; i < n; ++i) ++occ[s[i] - 65];
  for (int i = 0; i < 26; ++i) {
    if (occ[i] % 2 != 0) {
      if (oddIdx == -1) oddIdx = i;
      else {
        cout << "NO SOLUTION" << endl;
        return 0;
      }
    }
  }
  r = n / 2;
  l = r - 1;
  if (oddIdx != -1) {
    ns[r] = (char)(oddIdx + 65);
    ++r;
    --occ[oddIdx];
    while (occ[oddIdx] != 0) {
      ns[l] = ns[r] = (char)(oddIdx + 65);
      --l;
      ++r;
      occ[oddIdx] -= 2;
    }
  }
  for (int i = 0; i < 26; ++i) {
    while (occ[i] != 0) {
      ns[l] = ns[r] = (char)(i + 65);
      --l;
      ++r;
      occ[i] -= 2;
    }
  }
  cout << ns << endl;
  return 0;
}
