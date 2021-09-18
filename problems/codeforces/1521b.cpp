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


void solve(){
  int n;
  cin>>n;
  vector<ll> aa(n);
  rep(i,0,n-1)cin>>aa[i];
  auto it=min_element(all(aa));
  ll val=*it,nval;
  int idx=it-aa.begin()+1;
  cout<<n-1<<endl;
  rrep(i,idx-1,1){
    nval=(idx-i)%2?val+1:val;
    cout<<idx<<" "<<i<<" "<<val<<" "<<nval<<endl;
  }
  rep(i,idx+1,n){
    nval=(i-idx)%2?val+1:val;
    cout<<idx<<" "<<i<<" "<<val<<" "<<nval<<endl; 
  }
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

