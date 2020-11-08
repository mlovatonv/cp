#include <bits/stdc++.h>
#define N 50
using namespace std;

int n, m, a, b, nv, pathCount, s1Count, s2Count, s3Count;
bool v[N], g[N][N];
int s1[N], s2[N], s3[N], path[5];

void invalid() {
  cout << "-1" << endl;
  exit(0);
}

void dfs(int vi, int l) {
  v[vi] = true;
  path[pathCount++] = vi;
  if (l > 2 || pathCount > 3) invalid();
  for (int j = 1; j <= n; ++j)
    if (g[vi][j] && !v[j]) dfs(j, l + 1);
}

int main(void) {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a >> b;
    g[a][b] = true;
    g[b][a] = true;
    g[i][i] = true;
  }

  for (int i = 1; i <= n; ++i) {
    if (v[i]) continue;
    pathCount = 0;
    dfs(i, 0);
    //cout << i << " " << pathCount << endl;
    if (pathCount == 3) {
      for (int j = 0; j < 3; ++j) s3[s3Count++] = path[j];
    } else if (pathCount == 2) {
      for (int j = 0; j < 2; ++j) s2[s2Count++] = path[j];
    } else if (pathCount == 1) {
      s1[s1Count++] = path[0];
    }
  }

  if (s2Count / 2 > s1Count) invalid();
  int j = 0;
  for (int i = 0; i < n && s1Count && s2Count; i += 2) {
    s3[s3Count++] = s1[j++];
    s3[s3Count++] = s2[i];
    s3[s3Count++] = s2[i + 1];
    --s1Count;
    s2Count -= 2;
  }
  for (; j < n && s1Count >= 3; j += 3) {
    s3[s3Count++] = s1[j];
    s3[s3Count++] = s1[j + 1];
    s3[s3Count++] = s1[j + 2];
    s1Count -= 3;
  }
  if (s1Count) invalid();

  for (int i = 0; i < n; i += 3)
    cout << s3[i] << " " << s3[i + 1] << " " << s3[i + 2] << endl;
  return 0;
}
