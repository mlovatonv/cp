#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;
string s;
int cnt;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> s;
  sort(s.begin(), s.end());
  do {
    ++cnt;
  } while (next_permutation(s.begin(), s.end()));
  cout << cnt << endl;
  sort(s.begin(), s.end());
  do {
    cout << s << endl;
  } while (next_permutation(s.begin(), s.end()));
  return 0;
}
