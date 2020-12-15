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
const int inf=1e9;

vi adj[nmax];
vi topo;
int dist[nmax],state[nmax],p[nmax];
int n,m,w;

void read(){
  int u,v;
  cin>>n>>m;
  rep(e,1,m){
    cin>>u>>v;
    adj[u].pb(v);
  }
}

void dfs(int u,int p){ //encuentra ordenacion topologica inversa
  state[u]=1;
  ret(v,adj[u]){
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

int main(){
  fastio;
  read();
  rep(v,1,n)if(state[v]==0)dfs(v,v);
  rep(v,1,n)dist[v]=inf;
  dist[n]=0;
  ret(u,topo){
    ret(v,adj[u]){
      if(dist[v]==inf)continue;
      if(dist[u]==inf||dist[v]+1>dist[u]){
        dist[u]=dist[v]+1;
        p[u]=v;
      }
    }
  }
  if(dist[1]==inf){
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }
  cout<<dist[1]+1<<endl;
  w=1;
  do{
    cout<<w<<" ";
    w=p[w];
  }while(w!=n);
  cout<<n<<endl;
  return 0;
}

