#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define all(a) a.begin(),a.end()
#define sz size()
#define be begin()
#define emp empty()
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const ll mod=1e9+7;
const int nmax=1e5+10;

unordered_map<int,int> adj[nmax];
int n,m;
stack<int> pc,pc_;

void solve(){
  pc_.pu(1); // pila auxiliar
  while(!pc_.emp){
    int v=pc_.top();
    if(adj[v].sz==0){
      pc.pu(v);
      pc_.pop();
      continue;
    }
    int u=adj[v].be->fi;
    pc_.pu(u);
    adj[v].erase(u);
    adj[u].erase(v);
  }
}

int main(){
  fastio;
  cin>>n>>m;
  rep(i,1,m){
    int a,b;
    cin>>a>>b;
    adj[a][b]=1;
    adj[b][a]=1;
  }
  rep(i,1,n){
    if(adj[i].sz%2){
      cout<<"IMPOSSIBLE\n";
      return 0;
    }
  }
  solve();
  if(pc.sz!=m+1){
    cout<<"IMPOSSIBLE\n";
    return 0;
  }
  while(!pc.emp){
    cout<<pc.top()<<' ';
    pc.pop();
  }
  return 0;
}
