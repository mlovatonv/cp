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
  ll n;
  cin>>n;
  ll ans=-1;
  if(n==1){
    ans=1; 
  }elif(n==2){
    ans=2;
  }else{
    ans=((n-3)/4)*2+3;
    if(n%2==0){
      ++ans;
    }
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

