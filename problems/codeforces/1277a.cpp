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

int t;

void solve(){
  string s;
  cin>>s;
  int n=len(s);
  int prev=(n-1)*9;
  int ok=1;
  rep(i,1,n-1){
    if(s[0]>s[i]){
      ok=0;
      break;
    }
    if(s[i]>s[0]){
      break;
    }
  }
  int curr=(s[0]-'0')-1+ok;
  dbg(prev);
  dbg(curr);
  int ans=prev+curr;
  cout<<ans<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

