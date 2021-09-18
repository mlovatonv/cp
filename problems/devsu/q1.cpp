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
  string s1,s2;
  cin>>s1>>s2;
  int ans=-1;
  size_t p=s1.find(s2);
  if(p!=string::npos){
    int l=p;
    int r=len(s1)-p-len(s2);
    dbg(l);
    dbg(r);
    ans=max(l,r); 
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

