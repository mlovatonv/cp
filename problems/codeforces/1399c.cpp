#include <bits/stdc++.h>
#define N 55
using namespace std;

int t, n, maxTeams, teams, minS, maxS, a, b, sum;
int w[N];

int main(void)
{
  cin >> t;
  while (t--) {
    maxTeams = teams = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> w[i];
    if (n == 1) {
      cout << 0 << endl;
    } else if (n == 2) {
      cout << 1 << endl;
    } else {
      sort(w, w + n);
      minS = w[0] + w[1];
      maxS = w[n - 2] + w[n - 1];
      //cout << n << endl;
      //cout << "min max " << minS << " " << maxS << endl;
      int j = 0;
      for (int s = minS; s <= maxS; ++s) {
        for (; j < n && w[j] < s; ++j);
        a = 0;
        //cout << "j=" << j << endl;
        b = j - 1;
        teams = 0;
        while (a < b) {
          sum = w[a] + w[b];
          //cout << "a b sum s " << a << " " << b << " " << sum << " " << s << endl;
          if (sum == s) {
            //cout << "count!" << endl;
            ++teams;
            ++a;
            --b;
          } else if (sum < s) {
            ++a;
          } else if (sum > s) {
            --b;
          }
        }
        maxTeams = max(maxTeams, teams);
      }
      cout << maxTeams << endl;
    }
  }
  return 0;
}
