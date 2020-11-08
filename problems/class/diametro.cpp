#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int> adj[N];
int diam[N], punta[N];
int n, cont;

void diamDp(int x, int p) {
  diam[x] = 0;
  punta[x] = 0;
  int max1, max2, cont;
  max1 = max2 = -1;
  cont = 0;
  for (auto v : adj[x]) {
    if (v != p) {
      ++cont;
      diamDp(v, x);
      diam[x] = max(diam[x], diam[v]);
      if (punta[v] > max1) {
        max2 = max1;
        max1 = punta[v];
      } else {
        if (punta[v] > max2) {
          max2 = punta[v];
        }
      }
    }
  }
  if (cont <= 1)
    diam[x] = max(diam[x], max1 + 1);
  else
    diam[x] = max(diam[x], max1 + max2 + 2);
  punta[x] = max1 + 1;
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
  diamDp(1, 1);
  cout << diam[1] << endl;
}
