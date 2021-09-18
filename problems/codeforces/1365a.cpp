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
  int n,m;
  cin>>n>>m;
  vi r(n),c(m);
  rep(i,0,n-1)
    rep(j,0,m-1){
        int a;
        cin>>a;
        if(a)r[i]=c[j]=1;    
    }
  dbg(r);
  dbg(c);

  int a=0,b=0;
  rep(i,0,n-1)if(!r[i])++a;
  rep(i,0,m-1)if(!c[i])++b;
  dbg(a);
  dbg(b);
  int ans=min(a,b)%2;

  if(ans)cout<<"Ashish"<<endl;
  else cout<<"Vivek"<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)
  solve();
  return 0;
}

