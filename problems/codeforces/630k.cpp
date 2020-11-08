#include <bits/stdc++.h>
using namespace std;

long long int n, s;

int main(void)
{
  cin >> n;
  s = n - n / 2 - n / 3 - n / 5 - n / 7 + n / 6 + n / 10 + n / 14 + n / 15 + n / 21 + n / 35 - n / 30 - n / 42 - n / 70 - n / 105 + n / 210;
  cout << s << endl;
  return 0;
}
