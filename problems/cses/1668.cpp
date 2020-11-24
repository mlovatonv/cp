#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const ll mod=1e9+7;
const int nmax=1e5+5;

int n,m;
vi adj[nmax];
int t[nmax];
bool vis[nmax];
queue<int> q;

bool bfs(int x){
  t[x]=1;
  vis[x]=true;
  q.push(x);
  int i;
  while(!q.empty()){
    i=q.front();
    q.pop();
    ret(j,adj[i]){
      if(!vis[j]){
        t[j]=t[i]==1?2:1;
        vis[j]=true;
        q.push(j);
      }elif(vis[j]&&t[j]&&t[j]==t[i]){
        return false;
      }
    }
  }
  return true;
}

int main(){
  fastio;
  cin>>n>>m;
  rep(i,0,m){
    int a,b;
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  bool pos=true;
  rep(i,1,n+1)if(!vis[i])pos&=bfs(i);
  if(pos){
    rep(i,1,n+1)cout<<t[i]<<' ';
    cout<<'\n';   
  }else{
    cout<<"IMPOSSIBLE\n";
  }
  return 0;
}
