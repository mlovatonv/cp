#include <bits/stdc++.h>
#define N 1000005
#define DN 2000005
using namespace std;

int n, acc;
string s;
int b[N], idx[DN];

int main(void) {
  cin >> n;
  cin >> s;

  acc = 1e6;
  b[0] = acc;
  for (int i = 0; i < n; ++i) {
    acc += s[i] == '0' ? 1 : -1;
    if (idx[acc] == 0 && acc != 1e6) idx[acc] = i + 1;
    b[i + 1] = acc;
  }

  acc = 0;
  for (int i = 1; i <= n; ++i) acc = max(acc, i - idx[b[i]]);

  cout << acc << endl; 

  return 0;
}
