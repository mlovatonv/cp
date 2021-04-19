#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
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

const int ncolors=1e5+100;

void solve(){
  int n;
  cin>>n;

  vi c(n+1); // colors
  vi vis(n+1,0); // visited
  vi colorvis(ncolors,0); // color visits
  vector<vi> g(n+1); // graph
  vi good={1};

  rep(i,1,n+1)cin>>c[i];
  rep(i,1,n){
    int a,b;
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  function<void(int)> dfs=[&](int u){
    vis[u]=1;
    if(!colorvis[c[u]])good.pb(u);
    ++colorvis[c[u]];
    ret(v,g[u]){
      if(!vis[v]){
        dfs(v);
      }
    }
    --colorvis[c[u]];
  };
  colorvis[c[1]]=1;
  dfs(1);
  sort(all(good));
  ret(i,good)cout<<i<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

