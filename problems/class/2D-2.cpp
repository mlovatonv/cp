/*
 *  Time complexity: O(n)
 *  Explanation: n elements are checked
 *
 *  Space complexity: O(n)
 *  Explanation: n elements are stored
 *
 *  Idea: Check if it is possible to get to x,y using the given route.
 *  The total distance to be walked in each axis is calculated. Then, the target
 * coordinates are substracted from those distances and the remaining distance
 * should be an even number, so the target could be reached.
 */

#include <bits/stdc++.h>
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define ll long long
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define fi first
#define se second
using namespace std;

string s;
int n, x, y, distX, distY;
bool goY;

int main(void) {
  fastio;
  cin >> s;
  cin >> x >> y;
  n = s.size();
  int j = 0;
  rep(i, 0, n) {
    if (s[i] == 'T')
      goY = !goY;
    else {
      if (goY)
        ++distY;
      else
        ++distX;
    }
  }
  if (distX - abs(x) >= 0 && distY - abs(y) >= 0 && (distX - abs(x)) % 2 == 0 &&
      (distY - abs(y)) % 2 == 0)
    cout << "Si" << endl;
  else
    cout << "No" << endl;
  return 0;
}
