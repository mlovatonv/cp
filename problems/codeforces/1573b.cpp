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
  int n;
  cin>>n;
  vector<int> a(n),b(n);
  rep(i,0,n-1)cin>>a[i];
  rep(i,0,n-1)cin>>b[i];

  vector<pair<int,int>> mxb;
  int prev=0;
  rep(i,0,n-1){
    if(b[i]>prev){
      mxb.pb(mp(b[i],i));
      prev=b[i];
    }
  }
  
  dbg(mxb);

  int ans=INT_MAX,mgi;
  rep(i,0,n-1){
    mgi=lower_bound(all(mxb),mp(a[i],0))->se;
    dbg(a[i]);
    dbg(mgi);
    ans=min(ans,mgi+i); 
  }
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

