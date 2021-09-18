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


void solve(){
  int n,m;
  cin>>n>>m;
  vector<ll> aa(n),bb(m);
  rep(i,0,n-1)cin>>aa[i];
  rep(i,0,m-1)cin>>bb[i];
 
  ll p,mxi,mx=LLONG_MIN;
  rep(i,0,n-1){
    rep(j,0,m-1){
      p=aa[i]*bb[j];
      if(mx<p){
        mx=p;
        mxi=i;
      }
    }
  }
  mx=LLONG_MIN;
  rep(i,0,n-1){
    if(i!=mxi){
      rep(j,0,m-1){
        p=aa[i]*bb[j];
        mx=max(mx,p);
      }
    }
  }

  cout<<mx<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

