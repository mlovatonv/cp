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
  vi a(n+1),b(n+1);
  rep(i,0,n-1){
    int c;
    cin>>c;
    a[c]=i;
  }
  rep(i,0,n-1){
    int c;
    cin>>c;
    b[c]=i;
  }

  vi c(n+10);
  rep(i,1,n){
    int d=a[i]<=b[i]?b[i]-a[i]:n-a[i]+b[i];
    dbg(i);
    dbg(d);
    ++c[d];
  }
  int ans=*max_element(all(c));
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

