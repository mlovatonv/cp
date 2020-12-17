/*
 * Time complexity: O(n+m)
 * Explanation: A bfs costs O(n+m).
 *
 * Space complexity: O(n+m)
 * Explanation: A vector of adjacency lists for the nodes and an array to save the states.
 * 
 * Idea: Run a bfs and store the state of each node. This state can used to separate the
 * nodes into two groups and confirm if the graph is bicolorable. Then, we check how
 * many components were formed. If the number of components is more than one, the graph
 * is not connected. The maximum number of edges in a bicolorable graph is the product of
 * the number of nodes in the two groups. The maximum number of edges that you can add is
 * the mentioned maximum number of edges minus the current number of edges.
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

const ll mod=1e9+7;
const int nmax=2e5+5;
int n,m;
vi adj[nmax];
int t[nmax];

bool bfs(int x){
  queue<int> q;
  t[x]=1;
  q.push(x);
  int i;
  while(!q.empty()){
    i=q.front();
    q.pop();
    ret(j,adj[i]){
      if(!t[j]){
        t[j]=t[i]==1?2:1;
        q.push(j);
      }elif(t[j]==t[i]){
        return false;
      }
    }
  }
  return true;
}
 
int main(){
  fastio;
  cin>>n>>m;
  rep(i,1,m){
    int a,b;
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  int cnt=0; 
  rep(i,1,n)
    if(!t[i]){
      if(!bfs(i)){
        cout<<"NO ES BICOLORABLE"<<endl;
        return 0;
      }
      ++cnt;
    }
  if(cnt>1){
    cout<<"NO ES CONEXO"<<endl;
    return 0;
  }
  ll p1=0,p2=0;
  rep(i,1,n){
    if(t[i]==1)++p1;
    elif(t[i]==2)++p2;
  }
  cout<<(p1*p2-m)%mod<<endl;
  return 0;
}

