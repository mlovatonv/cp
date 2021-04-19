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

int t;

void solve(){
  ll n,r;
  cin>>n>>r;
  set<ll> s;
  rep(i,1,n){
    ll x;
    cin>>x;
    s.insert(x);
  }
  n=len(s);
  ll idx=n;
  int ans=0;
  for(auto it=s.rbegin();it!=s.rend();++it){
    if((*it)<=(r*(n-idx))){
      break;
    }
    ++ans;
    --idx; 
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

