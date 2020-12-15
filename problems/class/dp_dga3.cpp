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
using pll=pair<ll,ll>;

const int nmax=1e5+10;
const ll mod=1e9+7;
const ll inf=1e15;
const int inf=1e9;

pll adj[nmax],adjDAG[nmax]; //{weight,node}
vi topo;
int state[nmax];
ll paths[nmax],dist[nmax];
int n,m;
bool vis[nmax];
priority_queue<pll> q;

void read(){
  int u,v,w;
  cin>>n>>m;
  rep(e,1,m){
    cin>>u>>v>>w;
    adj[u].pb({v,w});
  }
}

void dijk(int s){
  rep(v,1,n){
    dist[v]=inf;
    vis[v]=false;
  }
  q.push({0,s});
  dist[s]=0;
  while(!q.empty()){
    pll par=q.top();
    q.pop();
    int u=par.se;
    if(vis[u])continue;
    vis[u]=true;
    ret(v,adj[par.se]){
      if(dist[v.fi]>dist[u]+v.se){
        if(dist[v.fi]=dist[u]+v.se;
        q.push({dist[v.fi],v.fi});
      }
    }
  }
}

void buildDAG(){

}

void dfsTopo(int u,int p){
  state[u]=1;
  ret(v,adjDAG[u]){
    if(state[v]==2)continue;
    if(v==p||state[v]==1){
      cout<<"IMPOSSIBLE"<<endl;
      exit(0);
    }
    dfs(v,u);
  }
  state[u]=2;
  topo.pb(u);
}

void countPath(){
  paths[n]=1;
  ret(u,topo){
    
  }
}

int maxShortestPath(){
  vi dist(n,inf2);// distancias maximas
  dist[n]=0;// en realidad calcularemos un camino invertido
  ret(u,topo){
    ret(v,adjDAG[u]){
      if(dist[v]==inf2)continue;
      if(dist[u]==inf2||dist[v]+1>dist[u])dist[u]=dist[v]+1;
    }
  }
  if(dist[1]==inf2){// esto nunca deberia pasar
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }
  return dist[1];
}

int minShortestPath(){
  vi dist(n,inf2);
  dist[n]=0;
  ret(u,topo){
    ret(v,adjDAG[u]){
      if(dist[v]==inf2)continue;
      if(dist[u]==inf2||dist[v]+1<dist[u])dist[u]=dist[v]+1;
    }
  }
  if(dist[1]==inf2){// esto nunca deberia pasar
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }
  return dist[1];
}

int main(){
  fastio;
  read();
  dijk(1);// corremos dijkstra
  cout<<dist[n]<<endl;
  buildDAG();//construimos DAG auxiliar, en este DAG, todo camino es un camino minimo
  dfsTopo(1,1);// encontramos una ordenacion topologica inversa en el DAG
  cout<<countPaths()<<endl;
  cout<<minShortestPath()<<endl;
  cout<<maxShortestPath()<<endl;
  return 0;
}

