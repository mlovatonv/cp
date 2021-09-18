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
  int n,x,y;
  cin>>n>>x>>y;
  string s;
  cin>>s;
  reverse(all(s));
  int ans=0;
  rep(i,0,y-1)ans+=s[i]!='0';
  ans+=s[y]!='1';
  rep(i,y+1,x-1)ans+=s[i]!='0';
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

