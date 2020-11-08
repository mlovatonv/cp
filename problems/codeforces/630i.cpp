#include <bits/stdc++.h>
using namespace std;

long long n, s;

int main(void)
{
  cin >> n;
  s = 24 * pow(4, n - 3) + 36 * (n - 3) * pow(4, n - 4);
  cout << s << endl;
  return 0;
}
