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
  string l;
  ll n,mx_n=2147483647;
  cin>>l;
  cin>>n;
  vector<pair<ll,ll>> v;
  ll a=len(l),b=0,s=len(l);
  while(b<mx_n){
    b+=a;
    v.pb({a,b}); // s=2 ? 2, 2
    a*=s;
  }
  string ans;
  ll prev;
  for(auto it=v.rbegin();it!=v.rend();++it){
    prev=it->se-it->fi;
    if(prev<n&&n<=it->se){
      ll part=it->fi/s;
      int l_pos=(n-prev-1)/part;
      ans+=l[l_pos];
      n-=(l_pos+1)*part;
    }
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

