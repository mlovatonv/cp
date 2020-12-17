/*
 * Time complexity: O(n+m)
 * Explanation: A bfs costs O(n+m).
 *
 * Space complexity: O(n+m)
 * Explanation: Multiple arrays to store an adjacency list for the graph and array to
 * mark the visited and the distances.
 *
 * Idea: Use multi-source bfs to get the shortest distance between a node in X and other
 * node in Y.
 */
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
using namespace std;
using ll=long long;
using vi=vector<int>;

const int nmax=2e5+100;
const int inf=INT_MAX;
vi adj[nmax];
int n,m;
bool vis[nmax];
int d[nmax];
int ans=inf;

//https://cp-algorithms.com/graph/breadth-first-search.html
void bfs(int x){
  queue<int> q;
  q.push(x);
  vis[x]=true;
  while(!q.empty()){
    int v=q.front();
    q.pop();
    ret(u,adj[v]){
      if(!vis[u]){
        vis[u]=true;
        q.push(u);
        d[u]=d[v]+1;
      }
    }
  }
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
  rep(i,1,n/5)adj[n+1].pb(i);
  rep(i,4*n/5,n)d[i]=inf;
  bfs(n+1);
  rep(i,4*n/5,n)ans=min(ans,d[i]);
  if(ans==inf)cout<<"INFINITO"<<endl;
  else cout<<ans-1<<endl;
  return 0;
}

