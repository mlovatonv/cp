/*
 * Time complexity: O(n+m)
 * Explanation: 2 dfs are needed and each one costs O(n+m).
 *
 * Space complexity: O(n)
 * Explanation: Multiple arrays to store an adjacency list for the graph and array to
 * mark the visited, the components and the order.
 *
 * Idea: To secure a corner, we need to ensure that there is path from a police station
 * and to a police station in a directed graph. So, we need to compute the strongly
 * connected components using the Ksoraju's algorithm, select the minimum cost in each
 * one and accumulate the values to get the minimum total cost.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define pb push_back
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;

const ll mod=1e9+7;
const ll inf=LLONG_MAX;
const int nmax=2e5+100;

int n,m;
vector<int> g1[nmax],g2[nmax];
ll ans=0;
bool vis[nmax];
vector<int> order,comp;

void dfs1(int v){
  vis[v]=true;
  ret(u,g1[v])if(!vis[u])dfs1(u);
  order.pb(v);
}

void dfs2(int v){
  vis[v]=true;
  comp.pb(v);
  ret(u,g2[v])if(!vis[u])dfs2(u);
}

int main(void){
  fastio;
  cin>>n>>m;
  rep(i,1,m){
    int u,v;
    cin>>u>>v;
    g1[u].pb(v);
    g2[v].pb(u);
  }

  rep(i,1,n)if(!vis[i])dfs1(i); //set order
  memset(vis,0,(n+1)*sizeof(bool)); //clean vis
  rep(i,1,n){ //get comp
    int v=order[n-i];
    if(!vis[v]){
      dfs2(v);

      ll minc=inf,c;
      ret(j,comp){
        c=(j*1LL*j*1LL)%mod;
        minc=min(minc,c);
      }
      if(minc!=inf){
        ans=ans%mod+minc%mod;
      }

      comp.clear();
    }
  }
  cout<<ans%mod<<endl;
  return 0;
}
