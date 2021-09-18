#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
bool ans=true;

void dfs(int x,int p){
  vis[x]=1;
  for(auto &i:g[x]){
    if(!vis[i]){
      dfs(i,x);
    }else if(i!=p){
      ans=false;
    }
  }
}

void solve(){
  int n,m,u,v;

  cin>>n>>m;
  g.resize(n+1);
  vis.resize(n+1);
  for(int i=0;i<m;++i){
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  dfs(1,0);

  for(int i=1;i<=n;++i){
    if(!vis[i]){
      ans=false;
      break;
    }
  }

  if(ans)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

int main(){
  solve();
  return 0;
}

