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
#define ret(i,c) for(auto &i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ll=long long;
using vi=vector<int>;

ll comb( ll n, ll k )
{
    ll result = n;
    for(ll i = n - 1; i > k ; --i ) {
        result *= i;
    }
    return result;
}

void solve(){
  ll s, u;
  cin >> s >> u;
  ll ans;
  if ((s - 1) > u){
    ans = 0; 
  } else {
    ans = comb(u, s);
    dbg(ans);
    if (s > 1) ans += comb(u, s - 1); 
  }
  cout << ans << endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

