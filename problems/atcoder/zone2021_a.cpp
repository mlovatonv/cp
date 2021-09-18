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
  string s;
  cin>>s;
  string ss="ZONe";
  int ans=0;
  size_t f=0;
  while(f!=string::npos){
    f=s.find(ss,f);
    if(f!=string::npos){
      f+=len(ss);
      ++ans;
    }else{
      break;
    }
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

