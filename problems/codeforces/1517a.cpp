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
  ll n;
  cin>>n;
  if(n%2050LL==0){
    string s=to_string(n/2050LL);
    int ans=0;
    ret(c,s){
      ans+=c-'0';
    }
    cout<<ans<<endl;
  }else{
    cout<<"-1"<<endl;
  }
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

