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
  int n;
  cin>>n;
  vi a(n+1);
  rep(i,1,n){
    cin>>a[i];
    a[i]-=i;
  }
  map<int,ll> mm;
  rep(i,1,n){
    if(mm.find(a[i])==mm.end()){
      mm[a[i]]=0;
    }
    ++mm[a[i]];
  }
  ll ans=0;
  ll acc;
  ret(i,mm){
    acc=((i.se-1LL)*i.se)/2LL;
    ans+=acc;
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

