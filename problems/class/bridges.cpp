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
using pii=pair<int,int>;
using vi=vector<int>;
using vii=vector<pii>;

const int nmax=1e3+10;
vii bridges;
vi adj[nmax];
int n,m,cont;
int low[nmax],pre[nmax],vis[nmax];

void dfs(int u,int p){
  pre[u]=cont++;
  low[u]=pre[u];
  vis[u]=1;
  ret(v,adj[u]){
    if(vis[v]){
      if(v!=p)low[u]=min(low[u],pre[v]); //ancestro que no es el padre
      continue;
    }
    dfs(v,u);
    if(low[v]==pre[v])bridges.pb({min(v,u),max(v,u)});
    low[u]=min(low[u],low[v]);
  }
}

void clear(){
  cont=0;
  rep(v,0,nmax){
    adj[v].clear();
    pre[v]=0;
    vis[v]=0;
  }
  bridges.clear();
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
  int t;
  cin>>t;
  rep(i,1,t){
    clear();
    read();
    dfs(1,1);
    sort(all(bridges));
    cout<<"Caso #"<<i<<endl;
    if(!len(bridges))cout<<"Sin bloqueos"<<endl;
    else{
      cout<<len(bridges)<<endl;
      ret(b,bridges){
        cout<<b.fi<<" "<<b.se<<endl; 
      }
    }
  }
  return 0;
}

