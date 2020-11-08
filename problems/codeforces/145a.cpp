#include <bits/stdc++.h>
using namespace std;

string a, b;
int notEqual4, notEqual7;

int main() {
  cin >> a >> b;
  for (int i = 0; i < a.size(); ++i) {
    //cout << a[i] << " " << b[i] << endl;
    if (a[i] == '4' && b[i] == '7') ++notEqual7;
    else if (a[i] == '7' && b[i] == '4') ++notEqual4;
    //cout << notEqual4 << " " << notEqual7 << endl;
  }
  cout << max(notEqual4, notEqual7) << endl;
  return 0;
}
