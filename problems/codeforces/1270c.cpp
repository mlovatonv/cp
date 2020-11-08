#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int t, n;
long long a, sumA, curXor;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    sumA = 0;
    curXor = 0;
    for (int i = 0; i < n; ++i) {
      //cout << sumA << " " << curXor << endl;
      cin >> a;
      sumA += a;
      curXor ^= a;
    }
    //cout << sumA << " " << curXor << endl;
    cout << 2 << endl << curXor << " " << sumA + curXor << endl;
  }
  return 0;
}
