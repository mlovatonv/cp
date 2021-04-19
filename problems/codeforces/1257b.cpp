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

int ceil(int x,int y){
  return 1+((x-1)/y);
}

void solve(){
  int x,y;
  cin>>x>>y;
  if(y<=x){
    cout<<"YES"<<endl;
    return;
  }
  int foo;
  int prev=-1;
  while(y!=prev){
    foo=ceil(y,3);
    foo=2*foo;
    prev=y;
    y=foo;
  }
  if(x<y)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

