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
using vi=vector<int>;


void solve(){
  int n;
  cin>>n;
  vector<int> p(n+1);
  rep(i,1,n){
    int j;
    cin>>j;
    p[i]=j;
  }
  int ans=0;
  function<void(int,int)> f=[&](int i,int lvl){
    ans=max(ans,lvl+1);
    if(p[i]==-1)return;
    f(p[i],lvl+1);
  };
  rep(i,1,n)f(i,0);
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

