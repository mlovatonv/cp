#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
using namespace std;
const ll mod=1e9+7;
const int nmax=1e6;

/*
 * tam = tamano de los centroides
 */

vi adj[nmax];
ll cnt;
int n,k,tam[nmax],dist[nmax],proc[nmax];

void read(){
  cin>>n>>k;
  int u,v;
  rep(i,1,n){
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
}

void dfsTam(int x,int y){
  int cont=1;
  for(auto u:adj[x]){
    if(u==y||proc[u])continue;
    dfsTam(u,x);
    cont+=tam[u];
  }
  tam[x]=cont;
}

void dfsMain(int x,int sz){
  rep(i,0,k)dist[i]=0;
  dfsDist(x);
  cantX(x); // contar los caminos que contienen a x en O(n)
  proc[x]=1;
  for(auto u:adj[x]){
    if(proc[u])continue;
    int nsz=(u==y)?sz-tam[x]:tam[u];
    dfsTam(u,0);
    pii par=getCentroid();
    int xx=par.fi; // centroide
    int yy=par.se;
    dfsMain(xx,yy,nsz);
  }
}

int main(void){
  fastio;
  read();
  dfsTam(1,0);
  getCentroid();
  dfsMain();
  cout<<cnt/2<<endl;
  return 0;
}
