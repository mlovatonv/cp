#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a;
bool v[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a;
    v[a] = true;
  }
  for (int i = 1; i <= n; ++i)
    if (!v[i]) {
      cout << i << endl;
      break;
    }

  return 0;
}
