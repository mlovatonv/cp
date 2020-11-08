#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, s;
const ll MOD = 1e9 + 7;

ll powerLL(ll x, ll n) {
  ll result = 1; 
  while (n) { 
    if (n & 1) result = result * x % MOD; 
    n = n / 2; 
    x = x * x % MOD; 
  } 
  return result; 
}
 

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  cout << powerLL(2, n) << endl;
  return 0;
}
