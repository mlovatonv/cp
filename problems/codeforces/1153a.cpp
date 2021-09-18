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

int ceil(int x,int y){
  return (x+y-1)/y;
}

void solve(){
  int n,t;
  cin>>n>>t;
  vector<pair<int,int>> sd(n);
  rep(i,0,n-1){
    int s,d;
    cin>>s>>d;
    sd[i]={s,d};
  }

  int ans=0,minf=INT_MAX;
  rep(i,0,n-1){
    int s=sd[i].fi,d=sd[i].se;
    int f=t<=s?s:d*ceil(t-s,d)+s;
    if(f<minf){
      ans=i;
      minf=f;
    }
  }
  cout<<ans+1<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

