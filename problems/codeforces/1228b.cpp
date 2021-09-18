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

const ll mod=1e9+7;

void solve(){
  int h,w;
  cin>>h>>w;
  vi rr(h),cc(w);
  vector<vi> mm(h+1,vi(w+1));
  rep(i,0,h-1)cin>>rr[i];
  rep(i,0,w-1)cin>>cc[i];
  
  rep(i,0,h-1){
    rep(j,0,rr[i]-1){
      mm[i][j]=1;
    }
    mm[i][rr[i]]=2;
  }
  rep(i,0,w-1){
    rep(j,0,cc[i]-1){
      if(mm[j][i]==2){
        cout<<"0"<<endl;
        return;
      }
      mm[j][i]=1;
    }
    if(mm[cc[i]][i]==1){
      cout<<"0"<<endl;
      return;
    }
    mm[cc[i]][i]=2;
  }

  ll ans=1;
  rep(i,0,h-1){
    rep(j,0,w-1){
      if(!mm[i][j])ans=(ans*2LL)%mod;
    }
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

