#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> b;

int main() {
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') b.push(s[i]);
    else if (s[i] == ')' && !b.empty() && b.top() == '(') b.pop();
    else b.push(s[i]);
  }
  cout << s.size() - b.size() << endl;
  return 0;
}
