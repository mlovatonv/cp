#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
const int N = 1e5 + 5;
int n, u, v;
vi g[N], picks;
bool goal[N], init[N], vis[N];

void flip(int node, int level, int even, int odd) {
  vis[node] = true;
  //cout << node << " " << level << " " << even << " " << odd << endl;
  if (level % 2 == 0) {
    if (even % 2 == 1) init[node] = !init[node];
  } else {
    if (odd % 2 == 1) init[node] = !init[node];
  }
  bool diff = init[node] != goal[node];
  if (diff) {
    picks.push_back(node);
    if (level % 2 == 0) ++even;
    else ++odd;
  }
  for (int &i : g[node]) if (!vis[i]) flip(i, level + 1, even, odd);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
  for (int i = 0; i < n; ++i) cin >> init[i];
  for (int i = 0; i < n; ++i) cin >> goal[i];

  flip(0, 0, 0, 0);
 
  cout << picks.size() << endl;
  for (int &i : picks) {
    cout << i + 1 << endl;
  }
  return 0;
}
