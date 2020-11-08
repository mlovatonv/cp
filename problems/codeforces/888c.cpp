#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
string s;
int idx, n, minDist = N;
int lastIndex[26], dist[26];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  fill_n(lastIndex, 26, -1);
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; ++i) {
    idx = s[i] - 97;
    //cout << i << " " << s[i] << " " << (int)idx << " " << dist[idx] << " " << i - lastIndex[idx] << endl;
    dist[idx] = max(dist[idx], i - lastIndex[idx]);
    lastIndex[idx] = i;
  }
  for (int i = 0; i < 26; ++i) {
    //cout << i << " " << dist[i] << " " << lastIndex[i] << endl;
    if (lastIndex[i] != -1) {
      dist[i] = max(dist[i], n - lastIndex[i]);
      minDist = min(minDist, dist[i]);
    }
  }
  if (minDist == 0) {
    minDist = n / 2 + 1;
  }
  cout << minDist << endl;
  return 0;
}
