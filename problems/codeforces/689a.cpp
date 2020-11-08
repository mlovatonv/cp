#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;
int n;
string d;
bool cel[10];

bool unq() {
  if (n == 1) return false;
  for (int i = 0; i < n; ++i) cel[d[i] - 48] = true;
  int moves = 4;
  // up
  if (cel[1] || cel[2] || cel[3]) --moves;
  // down
  if (cel[0] || cel[7] || cel[9]) --moves;
  // left
  if (cel[0] || cel[1] || cel[4] || cel[7]) --moves;
  // right
  if (cel[0] || cel[3] || cel[6] || cel[9]) --moves;
  return moves == 0;
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> d;
  if (unq()) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
