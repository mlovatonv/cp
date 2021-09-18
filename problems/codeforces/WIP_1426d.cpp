//https://codeforces.com/blog/entry/83120

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
  vector<ll> a(n);
  rep(i,0,n-1)cin>>a[i];

  map<ll,int> m;
  int ans=0;
  ll p=0;
  rep(i,0,n-1){
    p+=a[i];
    if(m.find(p)!=m.end()){
      p=0; 
      m.clear();
      ++ans;
    }
    m[p]=i;
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

