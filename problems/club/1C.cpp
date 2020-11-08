#include <bits/stdc++.h>
using namespace std;

string S;
int n, b, e;

int main(void) {
  cin >> S;
  n = S.size();

  b = 0;
  e = n - 1;
  while (b < e) {
    if (S[b++] != S[e--]) {
      cout << "No" << endl;
      return 0;
    }
  }

  b = 0;
  e = (n - 1) / 2 - 1;
  while (b < e) {
    if (S[b++] != S[e--]) {
      cout << "No" << endl;
      return 0;
    }
  }

  b = (n + 3) / 2 - 1;
  e = n - 1;
  while (b < e) {
    if (S[b++] != S[e--]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
