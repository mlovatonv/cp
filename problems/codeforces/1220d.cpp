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
  vector<ll> b(n);
  rep(i,0,n-1)cin>>b[i];

  ll mxb=*max_element(all(b));
  ll x=0,y=1;
  int minacc=3e5,acc=0;
  vector<ll> ans,temp;
  while(y<=mxb){
    acc=0;
    temp.clear();
    ret(i,b){
      if(__builtin_ctzll(i)!=x){
        ++acc;
        temp.pb(i);
      }
    }
    if(acc<minacc){
      minacc=acc;
      ans=temp;
    }
    ++x;
    y*=2LL; 
  }

  cout<<len(ans)<<endl;
  ret(i,ans)cout<<i<<' ';
}

int main(){
  fastio;
  solve();
  return 0;
}

