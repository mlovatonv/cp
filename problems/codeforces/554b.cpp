#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
string m[N];
int n, maxCnt;

void sweep(int i) {
  for (int j = 0; j < n; ++j) {
    m[j][i] = m[j][i] == '0' ? '1' : '0';
  }
}

int cleanedRows() {
  int rows = 0;
  bool clean;
  for (int i = 0; i < n; ++i) {
    clean = true;
    for (int j = 0; j < n; ++j) {
      if (m[i][j] == '0') {
        clean = false;
        break;
      }
    }
    if (clean) ++rows;
  }
  return rows;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
  }
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (m[i][j] == '0') {
        sweep(j);
        st.push(j);
      }
    }
    maxCnt = max(maxCnt, cleanedRows());
    while (!st.empty()) {
      sweep(st.top());
      st.pop();
    }
  }
  cout << maxCnt << endl;
  return 0;
}
