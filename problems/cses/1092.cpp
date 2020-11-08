#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  if ((n + 1) % 4 == 0) {
    cout << "YES" << endl;
    cout << n / 2 + 1 << endl << "1 2 ";
    for (int i = 4; i < n; i += 4) {
      cout << i << " " << i + 3 << " ";
    }
    cout << endl << n / 2 << endl << "3 ";
    for (int i = 4; i < n; i += 4) {
      cout << i + 1 << " " << i + 2 << " ";
    }
    cout << endl;
  } else if (n % 4 == 0) {
    cout << "YES" << endl;
    cout << n / 2 << endl;
    for (int i = 1; i < n; i += 4) {
      cout << i << " " << i + 3 << " ";
    }
    cout << endl << n / 2 << endl;
    for (int i = 1; i < n; i += 4) {
      cout << i + 1 << " " << i + 2 << " ";
    }
    cout << endl;
  } else cout << "NO" << endl;
  
  return 0;
}
