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
  ll a,b,c; 
  cin>>a>>b>>c;
  ll d=c-a-b;
  if(d>0&&(d*d)>(4*a*b)){
    cout<<"Yes"<<endl; 
  }else{
    cout<<"No"<<endl;
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

