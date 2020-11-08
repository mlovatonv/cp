/*
 * Time complexity: O(nlogn)
 * Explanation: The two dfs cost nlogn. The first dfs computes the distances and ancesters
 * in O(logn) for each node. The second dfs computes what is the farthest node at distance 
 * >= L in O(logn) for each node.
 *
 * Space complexity: O(nlogn)
 * Explanation: Two matrix of size nxlogn are used to store the ancesters and distances.
 * Also, some arrays of size n are used to store the cnt and dp values for each node. An
 * adjency list is used to store the tree.
 *
 * Idea: dp[v] is the number of nodes at distance <= L from the node v. This value can be
 * calculated as: dp[v]=1(itself)+sum(dp[u1],u[u2],...)-cnt[v], where u1,u2,... are its
 * children and cnt[v] is the number of nodes that have been considered as part of the
 * solution of the children but cannot be for the v because the distance between them is
 * greater than L. This will only happen at maximum one time for each child sub-tree. The
 * cnt[v] will be calculated in the children's sub-trees nodes. For example, in a node a,
 * we find the farthest node b upwards at distance <= L and then we sum 1 to the cnt value
 * of its parent. Hence, the parent won't count the node a. A brute force way to do this
 * is to check every ancester of the node a. To optimize this, we use binary lifting using
 * the ancesters and distances matrix. We accumulate the distances that need to be
 * accumulated because they are less or equal than L and we save the last node that meets
 * the requirement. Finally, we sum 1 to the cnt value of its parent since the last node
 * is the farthest node that is at distance <= L.
 * */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,ll>
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
const int nmax=2e5+100,lognmax=20;

int n,p,logn;
ll l,li;
int anc[nmax][lognmax]; // ancesters
ll dist[nmax][lognmax]; // distances
int cnt[nmax]; // number of nodes at distance >= L in the children's subtrees
int dp[nmax]; // number of nodes at distance <= L in the node's subtree
vector<pi> adj[nmax]; // fi=node se=distance

// precomputate distances and ancesters
void dfs1(int x,int p,ll d){
  anc[x][0]=p;
  dist[x][0]=d;
  rep(i,1,logn){
    int a=anc[x][i-1];
    anc[x][i]=anc[a][i-1];
    if(dist[a][i-1])dist[x][i]=dist[x][i-1]+dist[a][i-1];
  }
  for(auto &i:adj[x]){
    dfs1(i.fi,x,i.se);
  }
}

// count the number of nodes at distance <= L for each node
void dfs2(int x){
  // initialize dp with 1
  dp[x]=1;
  for(auto &i:adj[x]){
    dfs2(i.fi);
    dp[x]+=dp[i.fi];
  }
  //cout<<"dp["<<x<<"]="<<dp[x]<<endl;
  dp[x]-=cnt[x];

  // sum 1 to the cnt of the father of the farthest ancester at distance <= L
  int curr=x;
  ll accdist=0;
  for(int idx=logn;idx>=0;--idx){
    //cout<<"idx="<<idx<<" accdist="<<accdist<<" curr="<<curr<<endl;
    if(dist[curr][idx]!=0&&accdist+dist[curr][idx]<=l){
      accdist+=dist[curr][idx];
      curr=anc[curr][idx];
    }
    //cout<<"idx="<<idx<<" accdist="<<accdist<<" curr="<<curr<<endl;
  }
  curr=anc[curr][0];
  //cout<<"curr="<<curr<<endl<<endl;
  ++cnt[curr];
}

int main(void){
  fastio;
  cin>>n>>l;
  logn=ceil(log2(n));
  rep(i,2,n){
    cin>>p>>li;
    adj[p].push_back(mp(i,li));
  }
  dfs1(1,0,0);
  
  //cout<<"anc:"<<endl;
  //rep(i,0,n){
  //  rep(j,0,logn){
  //    cout<<anc[i][j]<<' '; 
  //  }
  //  cout<<endl;
  //}
  //cout<<endl;
  //cout<<"dist:"<<endl;
  //rep(i,0,n){
  //  rep(j,0,logn){
  //    cout<<dist[i][j]<<' '; 
  //  }
  //  cout<<endl;
  //}
  //cout<<endl;

  dfs2(1);
  //cout<<"cnt=";
  //rep(i,1,n)cout<<cnt[i]<<" ";
  //cout<<endl;
  rep(i,1,n){
    cout<<dp[i]<<endl;
  }
  return 0;
}
