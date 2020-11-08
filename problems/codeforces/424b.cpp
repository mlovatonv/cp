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

const int N = 1e3 + 5;
int n, s, sumK, targetS = 1e6;
int x, y;
int k[N];
double l, r, mid;
double dist[N];

int getPopu(double r1) {
  int popu = 0;
  rep(i, n) if (dist[i] < r1) popu += k[i];
  return popu;
}

int main() {
  fastio;
  cin >> n >> s;
  rep(i, n) {
    cin >> x >> y >> k[i];
    dist[i] = sqrt(x * x + y * y); 
    sumK += k[i];
    r = max(r, dist[i]);
  }
  targetS -= s;
  if (sumK < targetS) cout << -1 << endl;
  else {
    int it = 300;
    while (it--) {
      mid = l + (r - l) / 2;
      if (getPopu(mid) < targetS) l = mid;
      else r = mid;
    }
    cout << setprecision(8) << r << endl;
  }
  return 0;
}
