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
using ll=unsigned long long;
using vi=vector<int>;

ll ceil(ll x,ll y){
  if(x==0)return 0;
  return 1LL+((x-1LL)/y); 
}

ll foo(ll a,ll b,ll x){
  return b/x-ceil(a,x)+1LL;
}

void solve(){
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll n=b-a+1LL;
  ll ans=n-foo(a,b,c)-foo(a,b,d)+foo(a,b,lcm(c,d));
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

