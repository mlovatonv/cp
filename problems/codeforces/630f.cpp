#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define arr(a, n) a, a + n
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)
#define repr(i, n) for (int i = n - 1; i >= 0; --i)
#define repv(i, k, n) for (int i = k; i < n; ++i)
#define reprv(i, k, n) for (int i = k; i >= 0; --i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

ll comb[8];
ll n, s;

void build() {
  ll c = n, i = 1;
  for (; i < 7; ++i) {
    c /= i;
    comb[i] = c;
    c *= (n - i);
  }
  c /= i;
  comb[i] = c;
}

int main() {
  fastio;
  cin >> n;
  build();
  s = comb[5] + comb[6] + comb[7];
  cout << s << endl; 
  return 0;
}
