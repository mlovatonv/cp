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
int p[nmax];
bool vis[nmax];
queue<int> q;

void bfs(){
  p[1]=-1;
  vis[1]=true;
  q.push(1);
  int i;
  while(!q.empty()){
    i=q.front();
    q.pop();
    ret(j,adj[i])
      if(!vis[j]){
        p[j]=i;
        vis[j]=true;
        q.push(j); 
      }
  }
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
  bfs();
  if(!vis[n])cout<<"IMPOSSIBLE\n";
  else{
    vi path;
    for(int x=n;x!=-1;x=p[x])path.pb(x);
    reverse(all(path));
    cout<<path.size()<<'\n';
    ret(i,path)cout<<i<<" ";
    cout<<'\n';
  }
  return 0;
}
