/*
 * Time complexity: O(n + m)
 * Explanation: The n vertices and m edges are traversed using the dfs.
 *
 * Space complexity: O(n)
 * Explanation: An adjacency list is used to store the graph and a dp matrix of n x 2.
 *
 * Idea: dp[u][1] is the number of ways to name the tree if u is yang and dp[u][0] is the number of ways to name the tree if u is yin. To calculate the value of each vertex, we multiply the value of their children (sub-trees are independent) depending on the color (yang vertices cannot be adjacent).
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=3e5;

int n,v1,v2;
vector<int> adj[nmax];
ll aux1,aux2;
ll dp[nmax][2];
/* dp[u][1]=yang,dp[u][0]=ying */

void dfs(int x,int p){
  dp[x][0]=dp[x][1]=1LL;
  for(auto &i:adj[x]){
    if(i!=p){
      dfs(i,x);
      aux1=(dp[x][1]*dp[i][0])%mod;
      dp[x][1]=aux1;
      aux1=(dp[x][0]*dp[i][0])%mod;
      aux2=(dp[x][0]*dp[i][1])%mod;
      dp[x][0]=(aux1+aux2)%mod;
    }
  }
}

int main(void){
  fastio;
  cin>>n;
  rep(i,1,n){
    cin>>v1>>v2;
    adj[v1].pb(v2);
    adj[v2].pb(v1);
  }
  dfs(1,0);
  cout<<(dp[1][0]+dp[1][1])%mod<<endl;
  return 0;
}
