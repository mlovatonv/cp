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
  ll a,b,x,y,z;
  cin>>a>>b;
  if(b==2)b*=2;
  z=b;
  x=1;
  y=z-x;
  if(y<=1){
    cout<<"NO"<<endl;
    return;
  }
  cout<<"YES"<<endl<<a*x<<" "<<a*y<<" "<<a*z<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}
