/*
 * Time complexity: O(n+nlogn+qlogn)
 * Explanation: A dfs costs O(n) to go over the tree of n nodes. We use two dfs functions.
 * The first fills the dist and sz arrays, so this simply costs O(n). The other one 
 * updates the tree's root in each vertex to respond the queries. The update and query
 * operations cost O(logn) because we are using a segment tree with lazy propagation. Each
 * node is updated and each query in answered, so these operations in total cost O(nlogn)
 * for the updates and O(qlogn) for the queries.
 *
 * Space complexity: O(n+q)
 * Explanation: Multiple arrays of size n are used to store values related to the given
 * tree. Also, an array of vectors is used to store the queries by node. Two arrays of
 * size 4n are used for the segment tree and lazy propagation values.
 *
 * Idea: An efficient way to respond the queries is to group the queries by node and use a
 * segment tree to find the minimum distances to the leaves. First, we need to calculate
 * the distance from the root to any node and size of the sub-tree of each node. Given
 * that the given tree is an euler tour tree, we can use the order to separate which
 * vertices are part of the sub-tree of a specific vertex. Using this knowledge and the
 * distances and sizes computed before, the distances could be updated to return the
 * distances from a specific node to any node. Let u be a specific node and w its distance
 * from the root, to make u the new root we sum w to the distances of the nodes that are
 * not part of the sub-tree of u and substract w from the distances of the nodes in the
 * sub-tree. Then, for the queries, we need to find the minimum value in a range. The
 * nodes that are not leaves are ignored by setting their distances to infinite. These
 * updates and queries need to be fast given the constraints, so a segment tree is built
 * from the array of distances and we use lazy propagation to handle range updates.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define ret(i,c) for(auto i:c)
#define pb push_back
using namespace std;
using ll=long long;
using ii=array<int,2>;
using iii=array<int,3>;
using vii=vector<ii>;
using viii=vector<iii>;

const int nmax=5e5+5;
const ll inf=1e15;
int n,q;
vii adj[nmax];
viii que[nmax];
int sz[nmax];
ll dist[nmax];
ll ans[nmax];

// https://cp-algorithms.com/data_structures/segment_tree.html
ll tree[nmax*4],lazy[nmax*4];

void build(ll node,ll tl,ll tr){
  if(tl==tr){
    tree[node]=dist[tl+1];
  }else{
    ll tm=(tl+tr)/2;
    build(node*2,tl,tm);
    build(node*2+1,tm+1,tr);
    tree[node]=min(tree[node*2],tree[node*2+1]);
  }
}

void push(ll node){
  if(tree[node*2]<inf)tree[node*2]+=lazy[node];
  lazy[node*2]+=lazy[node];
  if(tree[node*2+1]<inf)tree[node*2+1]+=lazy[node];
  lazy[node*2+1]+=lazy[node];
  lazy[node]=0;
}

void update(ll node,ll tl,ll tr,ll l,ll r,ll val){
  if(l>r)return; //invalid
  if(l==tl&&tr==r){ //equal to range
    if(tree[node]<inf)tree[node]+=val;
    lazy[node]+=val;
  }else{ //inside range
    push(node);
    ll tm=(tl+tr)/2;
    update(node*2,tl,tm,l,min(r,tm),val);
    update(node*2+1,tm+1,tr,max(l,tm+1),r,val);
    tree[node]=min(tree[node*2],tree[node*2+1]);
  }
}

ll query(ll node,ll tl,ll tr,ll l,ll r){
  if(l>r)return inf; //invalid
  if(l<=tl&&tr<=r)return tree[node]; //inside range
  push(node);
  ll tm=(tl+tr)/2;
  return min(
      query(node*2,tl,tm,l,min(r,tm)),
      query(node*2+1,tm+1,tr,max(l,tm+1),r)
  );
}

int dfs1(int x,int p){
  int currsz=1;
  ret(i,adj[x]){
    int u=i[0];
    if(u!=p){
      dist[u]=dist[x]+i[1];
      currsz+=dfs1(u,x);
    }
  }
  sz[x]=currsz-1;
  return currsz;
}

void dfs2(int x,int p){
  ret(i,que[x]){
    int idx=i[0],l=i[1]-1,r=i[2]-1;
    ans[idx]=query(1,0,n-1,l,r);
    if(ans[idx]==inf)ans[idx]=0;
  }
  ret(i,adj[x]){
    int u=i[0],w=i[1];
    if(u!=p){
      // reroot to u
      update(1,0,n-1,0,n-1,w);
      update(1,0,n-1,u-1,u-1+sz[u],-2*w);
      dfs2(u,x);
      // reroot to x
      update(1,0,n-1,0,n-1,-w);
      update(1,0,n-1,u-1,u-1+sz[u],2*w);
    }
  }
}

int main(){
  fastio;
  cin>>n>>q;
  rep(i,1,n-1){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].pb({v,w});
    adj[v].pb({u,w});
  }
  rep(i,1,q){
    int u,l,r;
    cin>>u>>l>>r;
    que[u].pb({i,l,r});
  }
  dfs1(1,0); // set sz and dist
  rep(i,1,n)if(sz[i])dist[i]=inf; // disqualify non-leaf
  build(1,0,n-1);
  dfs2(1,0); // set ans
  rep(i,1,q)cout<<ans[i]<<'\n';
  return 0;
}

