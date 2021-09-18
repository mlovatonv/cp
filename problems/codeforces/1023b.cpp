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
  ll n,k,ans;
  cin>>n>>k;
  if(k<=n){
    ans=(k-1LL)/2LL;
  }else{
    if(k-n>n){
      ans=0;
    }else{
      ans=((2LL*n)-k+1LL)/2LL; 
    }   
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

