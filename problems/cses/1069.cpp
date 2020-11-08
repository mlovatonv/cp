#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, cnt;
char s[N];
int maxLength = 1;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> s;
  cnt = 1;
  for (int i = 1; s[i] != '\0'; ++i) {
    if (s[i - 1] != s[i]) {
      cnt = 1;
    } else {
      ++cnt;
    }
    maxLength = max(maxLength, cnt);
  }
  cout << maxLength << endl;
  return 0;
}
