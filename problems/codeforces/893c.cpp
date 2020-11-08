#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
unsigned n, m, x, y;
vector<list<unsigned>> g(N);
bool visited[N];
long long sumMinGold;
long long gold[N];

int search(int node) {
  visited[node] = true;
  int minGold = gold[node];
  for (
      list<unsigned>::iterator it = g[node].begin();
      it != g[node].end();
      ++it
      ) {
    if (!visited[*it]) minGold = min(minGold, search(*it));
  }
  return minGold;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> gold[i];
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
    g[y - 1].push_back(x - 1);
  }
  for (int i = 0; i < n; ++i) 
    if (!visited[i]) sumMinGold += search(i);
  cout << sumMinGold << endl;
  return 0;
}
