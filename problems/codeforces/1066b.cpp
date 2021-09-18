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
  int n,r;
  cin>>n>>r;
  vi a(n);
  rep(i,0,n-1)cin>>a[i];
  int i=0,j=0,k=0,ans=0;
  while(i<n){
    j=min(i+r-1,n-1);
    i=max(i-r+1,0);
    
    k=-1;
    while(i<=j){
      if(a[i]==1)k=i;
      ++i;
    }
    if(k==-1){
      cout<<-1<<endl; //invalid
      return;
    }

    i=k+r;
    ++ans;
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

