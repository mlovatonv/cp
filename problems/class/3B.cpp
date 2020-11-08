/*
 * Time complexity: O(n + m)
 * Explanation: The n vertices and m edges are traversed using the dfs.
 *
 * Space complexity: O(n)
 * Explanation: An adjacency list is used to store the graph and a dp matrix of n x 2.
 *
 * Idea: We use the dp[u][taken?] to store the maximum number of pairs if the node u is taken or not.
 * We use a dfs to traverse the tree and set the dp values. If the node u is not taken, we sum the
 * maximum values of the children (taken or not). If the node u is taken, we need to select the child
 * with the maximum value (in the case it is not taken) and the sum of the maximum values of the rest
 * (taken or not).
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
const int nmax=3e5+1;

int n,v1,v2;
vector<int> adj[nmax];
int dp[nmax][2];
/* dp[u][1]=taken,dp[u][0]=not taken */

void dfs(int x,int p){
  int mxdp=0,mxi=0;
  for(auto &i:adj[x]){
    if(i!=p){
      dfs(i,x);
      dp[x][0]+=max(dp[i][1],dp[i][0]);
    }
  }
  for(auto &i:adj[x]){
    if(i!=p){
      dp[x][1]=max(dp[x][1],dp[x][0]-max(dp[i][1],dp[i][0])+dp[i][0]+1);
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
  cout<<max(dp[1][0],dp[1][1])<<endl;
  return 0;
}
