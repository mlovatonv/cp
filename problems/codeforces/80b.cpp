#include <bits/stdc++.h>
using namespace std;

string s;
double hours, mins, x, y;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> s;
  hours = (s[0] - 48) * 10 + s[1] - 48;
  mins = (s[3] - 48) * 10 + s[4] - 48;
  //cout << hours << " " << mins << endl;
  x = hours == 12 ? 0 : hours > 12 ? (hours - 12) * 30 : hours * 30;
  x += 30 * (mins / 60);
  y = mins * 6;
  cout << x << " " << y << endl;
  return 0;
}
