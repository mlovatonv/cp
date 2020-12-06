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

const int nmax=1e4+10;
int n,m,cont;
vi adj[nmax];
int artic[nmax],low[nmax],pre[nmax];

void dfs(int u,int p){
  pre[u]=cont++;
  low[u]=pre[u];
  int nh=0;
  ret(v,adj[u]){
    if(pre[v]){
      if(v!=p)low[u]=min(low[u],pre[v]);
      continue;
    }
    dfs(v,u);
    if(u!=p&&low[v]>=pre[u])artic[u]=1; // articulaciones dif a raiz
    low[u]=min(low[u],low[v]);
    ++nh;
  }
  if(u==p&&nh>1)artic[u]=1; // raiz
}

void clear(){
  cont=1;
  rep(v,0,n){
    adj[v].clear();
    pre[v]=0;
    artic[v]=0;
  }
}

void read(){
  int u,v;
  cin>>n>>m;
  rep(i,1,m){
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
}

int main(){
  fastio;
  while(true){
    clear();
    read();
    if(n==0)break;
    dfs(1,1);
    int sol=0;
    rep(i,1,n)if(artic[i])++sol;
    cout<<sol<<endl;
  }
  return 0;
}

