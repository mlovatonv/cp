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
  int n,k;
  string s;
  cin>>n>>k;
  cin>>s;
  
  if(n==k){
    cout<<s<<endl;
    return;
  }
 
  string ans;
  ans.resize(k);
  int cnt=0,cnt2=0,j;
  rep(i,0,n-1){
    if(s[i]=='(')++cnt;
    else ++cnt2;
    ans[i]=s[i];
    if(((i+1)-cnt2+cnt)==k){
      j=i+1;
      break;
    }
  }
  rep(i,j,k-1){
    ans[i]=')';
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

