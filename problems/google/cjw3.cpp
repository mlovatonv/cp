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

vi solve(){
  vi ans;
  int m,n,p,t;
  cin>>m>>n>>p;
  t=m+n;
  vector<vi> g(t);
  rep(i,0,t-1){
    string s;
    cin>>s;
    rep(j,0,t-1){
      if(j=='Y'&&j!=i){
        g[i].pb(j);
      }
    }
  }
  rep(i,0,p){
    int a,b;
    cin>>a>>b;
    --a;
    --b;
    // a and b know each other
    if(find(all(g[a]),b)!=g[a].end()){
      ans.pb(0);
      continue;
    }
    // a manager know both
  }
  return ans;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t){
    cout<<"Case #"<<i<<": ";
    ret(j,solve())cout<<j<<" ";
    cout<<endl;
  }
  return 0;
}

