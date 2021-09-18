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

  vector<ll> l{1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

  int ans=0;
  ret(i,l){
    if(i*10LL>n&&n>=i){
      dbg(n);
      dbg(i);
      dbg(n/i);
      ans=(n/i+1LL)*i-n;
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

