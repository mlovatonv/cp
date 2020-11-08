#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;
ll k, p, kZcy, sumK;
string s, rs;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> k >> p;
  for (int i = 1; i <= k; ++i) {
    s = rs = to_string(i);
    reverse(rs.begin(), rs.end());
    s += rs;
    //cout << s << endl;
    kZcy = stoll(s);
    sumK += kZcy;
  };
  cout << sumK % p << endl;
  return 0;
}
