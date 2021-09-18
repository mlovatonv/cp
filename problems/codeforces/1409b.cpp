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


void solve(){
  ll a,b,x,y,n,n2,a1,a2,b1,b2;
  cin>>a>>b>>x>>y>>n;
  a1=a2=a;
  b1=b2=b;
  
  n2=n-(b-y);
  b1=max(b1-n,y);
  if(n2>0){
    a1=max(a1-n2,x);
  }

  n2=n-(a-x);
  a2=max(a2-n,x);
  if(n2>0){
    b2=max(b2-n2,y);
  }
  
  ll ans=min(a1*b1,a2*b2);
  cout<<ans<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)
  solve();
  return 0;
}

