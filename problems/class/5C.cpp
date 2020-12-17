/*
 * Time complexity: O(n+m)
 * Explanation: A dfs costs O(n+m).
 *
 * Space complexity: O(n+m)
 * Explanation: Multiple arrays to store an adjacency list for the graph and array to
 * mark the visited, the low and the pre.
 *
 * Idea: The tarjan algorithm is used to find the bridges in the graph and return the one
 * with the minimum cost. Also, we only need to consider the bridges that are in a path
 * between nodes 1 and n. This can be done by starting the dfs in 1 and checking if n is
 * in the sub-tree of the node that is being checked.
 */

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

const int nmax=2e5+10;
const int inf=1e9;

vi adj[nmax];
int n,m,cont,ans=inf;
int low[nmax],pre[nmax];
bool vis[nmax];

bool dfs(int u,int p){
  pre[u]=cont++;
  low[u]=pre[u];
  vis[u]=1;
  bool nisdown=false;
  ret(v,adj[u]){
    if(vis[v]){
      if(v!=p)low[u]=min(low[u],pre[v]);
      continue;
    }
    if(dfs(v,u)){
      nisdown=true;
      if(low[v]==pre[v])ans=min(ans,u+v);
    }
    low[u]=min(low[u],low[v]);
  }
  return (u==n)||nisdown;
}

int main(){
  fastio;
  cin>>n>>m;
  rep(i,1,m){
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u); 
  }
  dfs(1,1);
  if(ans==inf)cout<<0<<endl;
  else cout<<ans<<endl;
  return 0;
}

