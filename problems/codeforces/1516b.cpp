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
using vi=vector<ll>;


void solve(){
  int n;
  cin>>n;
  vi a(n);
  rep(i,0,n-1)cin>>a[i];
  vi pre(n);
  pre[0]=a[0];
  rep(i,1,n-1){
    pre[i]=pre[i-1]^a[i];
  }
  // 2 pieces
  rep(i,1,n-1){
    if(pre[i-1]==(pre[i-1]^pre[n-1])){
      cout<<"YES"<<endl;
      return;
    }
  }
  // 3 pieces
  rep(i,1,n-2){
    rep(j,i+1,n-1){
      if(pre[i-1]==(pre[i-1]^pre[j-1])&&pre[i-1]==(pre[j-1]^pre[n-1])){
        cout<<"YES"<<endl;
        return;
      }
    }
  }
  // not possible
  cout<<"NO"<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

