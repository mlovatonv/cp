#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ll=long long;

ll comb(ll n, ll k)
{
  if (k > n) return 0;
  if (k * 2 > n) k = n-k;
  if (k == 0) return 1;

  ll result = n;
  for(ll i = 2; i <= k; ++i) {
      result *= (n - i + 1);
      result /= i;
  }
  return result;
}

ll sets(ll n)
{
  ll ans = 0;
  for(ll i = 2; i <= n; ++i){
    ans += comb(n, i);
  }
  return ans;
}


void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<int>> mm(n, vector<int>(m));
  rep(i, 0, n - 1) rep(j, 0, m - 1) cin >> mm[i][j];
  ll ans = m * n, acc0 = 0, acc1 = 0;
  rep(i, 0, n - 1)
  {
    acc0 = 0, acc1 = 0;
    rep(j, 0, m - 1)
    {
      if(mm[i][j]) ++acc1;
      else ++acc0;
    }
    if(acc1 > 1) ans += sets(acc1);
    if(acc0 > 1) ans += sets(acc0);
  }
  rep(i, 0, m - 1)
  {
    acc0 = 0, acc1 = 0;
    rep(j, 0, n - 1)
    {
      if(mm[j][i]) ++acc1;
      else ++acc0;
    }
    if(acc1 > 1) ans+= sets(acc1);
    if(acc0 > 1) ans+= sets(acc0);
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();
  return 0;
}

