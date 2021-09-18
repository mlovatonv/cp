#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int n,u,v,maxu,maxd=0;

void dfs(int u,int p,int d){
  int l=0;
  for(auto &i:g[u]){
    if(i!=p){
      ++l;
      dfs(i,u,d+1);
    }
  }
  if(l==0&&maxd<d){
    maxd=d;
    maxu=u;
  }
}

int main(){
  cin>>n;
  g.resize(n+1);

  for(int i=0;i<n-1;++i){
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1,0,0);
  maxd=0;
  dfs(maxu,0,0);

  cout<<maxd<<endl;

  return 0;
}

