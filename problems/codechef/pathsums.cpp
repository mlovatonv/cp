#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=1e2+1;

int n,t,u,v;
vector<int> adj[nmax];
int a[nmax];

void dfs(int x, int p, bool flag){
  a[x]=1+flag;
  for(auto i:adj[x]){
    if(i!=p){
      dfs(i,x,!flag);
    }
  }
}

void solve(){
  cin>>n;
  rep(i,1,n)adj[i].resize(0);
  memset(a,0,(n+1)*sizeof(int));
  rep(i,1,n-1){
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1,0,0);
  rep(i,1,n)cout<<a[i]<<' ';
  cout<<endl;
}

int main(void){
  fastio;
  cin>>t;
  while(t--)solve();
  return 0;
}
