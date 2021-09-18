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

int getdest(string s){
  return (
      count_if(all(s),[](char i){ return i=='+'; })
      -count_if(all(s),[](char i){ return i=='-'; })
  );
}

void solve(){
  string s1,s2;
  cin>>s1;
  cin>>s2;
  int n=len(s1);
  int s1dest=getdest(s1);
  vi k;
  rep(i,0,n-1)if(s2[i]=='?')k.pb(i);
  dbg(k);
  int nk=len(k);
  double total=1<<nk;
  double ans=0;
  rep(i,0,total-1){
    rep(j,0,nk-1){
      s2[k[j]]=(i&(1<<j))?'+':'-';
    }
    if(getdest(s2)==s1dest)++ans;
  }
  dbg(ans);
  dbg(total);
  ans /= total;
  cout<<fixed<<setprecision(12)<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

