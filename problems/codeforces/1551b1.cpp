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
  string s;
  cin>>s;
  map<char,int> m;
  ret(c,s)++m[c];
  int c1=0,c2=0;
  ret(p,m){
    if(p.se>1)++c1;
    else ++c2;
  }
  int ans=c1+c2/2;
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

