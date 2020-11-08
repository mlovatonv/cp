#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n, m, k, x, y, maxD;
int d[N][N];

inline int calc(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  cin >> n >> m >> k;
  for (int r = 1; r <= n; ++r)
  for (int c = 1; c <= m; ++c) d[r][c] = 4e3;
  for (int i = 0; i < k; ++i) { cin >> x >> y;
  for (int r = 1; r <= n; ++r)
  for (int c = 1; c <= m; ++c) d[r][c] = min(d[r][c], calc(r, c, x, y)); }
  for (int r = 1; r <= n; ++r)
  for (int c = 1; c <= m; ++c) if (d[r][c] > maxD) maxD = d[r][c], x = r, y = c;
  cout << x << " " << y << endl;
  return 0;
}
