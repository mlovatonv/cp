#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(long long i=s;i<=e;++i)
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
using vi=vector<int>;

const ll mod=1e9+7;

void solve(){
  ll n;
  cin>>n;
  ll foo10=1,foo9=1,foo8=1;
  rep(i,1,n){
    foo10=(foo10*10LL)%mod;
    foo9=(foo9*9LL)%mod;
    foo8=(foo8*8LL)%mod; 
  }
  dbg(foo10);
  dbg(foo9);
  dbg(foo8);
  ll ans=(foo10-foo9-foo9+foo8)%mod;
  ans=(ans+mod)%mod;
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

