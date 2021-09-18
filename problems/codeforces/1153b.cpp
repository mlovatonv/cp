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
  int n,m,h;
  cin>>n>>m>>h;
  vi a(m),b(n);
  vector<vi> c(n,vi(m));
  rep(i,0,m-1)cin>>a[i];
  rep(i,0,n-1)cin>>b[i];
  rep(i,0,n-1)rep(j,0,m-1)cin>>c[i][j];

  vector<vi> ans(n,vi(m,-1));
  rep(i,0,n-1)rep(j,0,m-1)if(b[i]==a[j])ans[i][j]=b[i];
  rep(i,0,n-1)rep(j,0,m-1)if(c[i][j]==0)ans[i][j]=0;
  rep(i,0,n-1){
    rep(j,0,m-1){
      if(ans[i][j]==-1){
        ans[i][j]=min(b[i],a[j]);
      }
    }
  }

  rep(i,0,n-1){
    rep(j,0,m-1){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

