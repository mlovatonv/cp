#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 5;
int n, p, cnt;
list<int> g[N];
int c[N];

void color(int node, int parentColor) {
  if (parentColor != c[node]) ++cnt;
  for (list<int>::iterator it = g[node].begin(); it != g[node].end(); ++it)
    color(*it, c[node]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> p;
    g[p - 1].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  color(0, 0);
  cout << cnt << endl;
  return 0;
}
