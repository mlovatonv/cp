#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
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

int n, k;
int dist[26];

void solve() {
  scanf("%d %d", &n, &k);
  char s[n + 1];
  scanf("%s", s);
  if (n * 25 < k) {
    printf("-1\n");
    return;
  }
  for (int i = 25; i >= 13; --i) {
    dist[25 - i] = i;
    dist[i] = -i;
  }
  for (int i = 0; i < n && k != 0; ++i) {
    int j = s[i] - 97;
    int udist = abs(dist[j]);
    //cout << s[i] << " " << udist << " " << k << endl;
    if (k < udist) {
      j += j < 13 ? k : -k;
      k = 0;
    } else {
      k -= udist;
      j += dist[j];
    }
    s[i] = j + 97;
  }
  if (k > 0) printf("-1\n");
  else printf("%s\n", s);
}

int main() {
  fastio;
  solve();
  return 0;
}
