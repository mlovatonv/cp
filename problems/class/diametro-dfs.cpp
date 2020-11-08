#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int> adj[N];
int n;

pair<int, int> dfs(int x, int p) {
  pair<int, int> resx = {0, x};
  for (auto u : adj[x]) {
    if (u != p) {
      auto resu = dfs(u, x);
      if (resu.first + 1 > resx.first) {
        resx.first = resu.first + 1;
        resx.second = resu.second;
      }
    }
  }
  return resx;
}

void read() {
  cin >> n;
  int u, v;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

int main() {
  read();
  auto res1 = dfs(1, 1);
  cout << dfs(res1.second, res1.second).first << endl;
  return 0;
}
