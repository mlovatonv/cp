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
const ll mod=1e9+7;

vi adj[nmax],adjT[nmax];
vi topo;
int paths[nmax],state[nmax];
int n,m;

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
  rep(v,1,n){
    if(state[v]==0)dfs(v,v);
  }
  paths[n]=1;
  ret(u,topo)
    ret(v,adj[u]){
      paths[u]+=(paths[v]%mod);
      paths[u]%=mod;
    }
  cout<<paths[1]<<endl;
  return 0;
}

