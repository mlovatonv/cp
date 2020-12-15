#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
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

const int nmax=1e5+10;
vi adj[nmax];
int n,m,cont,cont2;
int pre[nmax],low[nmax],scc[nmax];
stack<int> pila;


void dfs(int u){
  pre[u]=cont++;
  pila.push(u);
  low[u]=pre[u];
  ret(v,adj[u]){
    if(pre[v]!=-1){
      if(scc[v]==-1)low[u]=min(low[u],pre[v]);
      continue; 
    }
    dfs(v);
    low[u]=min(low[u],low[v]);
  }
  if(low[u]==pre[u]){ //cabeza
    int w;
    do{
      w=pila.top();
      pila.pop(); 
      scc[w]=cont2;
    }while(w!=u);
    ++cont2;
  }
}

void read(){
  int u,v;
  cin>>n>>m;
  rep(i,1,m){
    cin>>u>>v;
    adj[u].pb(v);
  }
  rep(v,1,n){
    pre[v]=-1;
    scc[v]=-1;
  }
  cont2=1;
}

int main(){
  fastio;
  read();
  rep(u,1,n){
    if(scc[u]==-1)dfs(u);
  }
  cout<<cont2-1<<endl;
  rep(u,1,n)cout<<scc[u]<<' ';
  cout<<endl;
  return 0;
}

