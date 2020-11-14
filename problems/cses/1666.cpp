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
const int nmax=1e5+100,mmax=2e5+100;
vector<int> adj[nmax];
vector<int> comp,comproot;
bool vis[nmax];
int n,m;

void dfs(int x){
  comp.pb(x);
  vis[x]=true;
  for(auto i:adj[x]){
    if(!vis[i]){
      dfs(i);
    }
  }
}

int main(void){
  fastio;
  cin>>n>>m;
  rep(i,1,m){
    int a,b;
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  rep(i,1,n){
    if(!vis[i]){
      comp.clear();
      dfs(i);
      comproot.pb(i);
    }
  }
  int ans=comproot.size()-1;
  cout<<ans<<endl;
  rep(i,0,ans-1){
    cout<<comproot[i]<<" "<<comproot[i+1]<<endl;   
  }
  return 0;
}
