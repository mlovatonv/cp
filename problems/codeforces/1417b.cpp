#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int t, n;
long long T, whiteMax, blackMin;
long long a[N];
/* white = 0, black = 1 */
bool color[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> T;
    memset(color, 0, n * sizeof(bool));
    whiteMax = 0, blackMin = 1e9;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[i] + a[j] == T) {
          if (a[i] <= a[j]) {
            color[i] = 0;
            color[j] = 1;
            whiteMax = max(whiteMax, a[i]);
            blackMin = min(blackMin, a[j]);
          } else {
            color[i] = 1;
            color[j] = 0;
            whiteMax = max(whiteMax, a[j]);
            blackMin = min(blackMin, a[i]);
          }
        }
      }
      if (a[i] < whiteMax || a[i] + whiteMax < T) {
        color[i] = 0;
        whiteMax = max(whiteMax, a[i]);
      } else if (blackMin < a[i] || a[i] + blackMin > T) {
        color[i] = 1;
        blackMin = min(blackMin, a[i]);
      }
    }

    for (int i = 0; i < n; ++i) cout << color[i] << " ";
    cout << endl;
  }
  return 0;
}
