#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
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

const int nmax=1005,nnmax=nmax*nmax;
int n,m,a,b;
string g[nmax];
bool valid[nnmax],vis[nnmax];
int d[nnmax],p[nnmax];
queue<int> q;
char act[nnmax];

void check(int v,int u,char c){
  if(!valid[u]||vis[u])return;
  vis[u]=true;
  q.push(u);
  d[u]=d[v]+1;
  p[u]=v;
  act[u]=c;
}

void bfs(int x){
  q.push(x);
  vis[x]=true;
  p[x]=-1;
  int v;
  while(!q.empty()){
    v=q.front();
    q.pop();
    check(v,v-1,'L');
    check(v,v+1,'R');
    check(v,v-m-2,'U');
    check(v,v+m+2,'D');
  }
}

void init(int x){
  g[x]="";
  rep(i,0,m+1){
    g[x]+="#";
  }   
}

int main(void){
  fastio;
  cin>>n>>m;
  init(0);
  init(n+1);
  rep(i,1,n){
    string s;
    cin>>s;
    g[i]="#"+s+"#";
  }
  rep(i,0,n+1){
    rep(j,0,m+1){
      int k=i*(m+2)+j;
      if(g[i][j]=='A')a=k;
      if(g[i][j]=='B')b=k;
      valid[k]=g[i][j]!='#';
    }
  }
  bfs(a);
  if(d[b]==0){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
    cout<<d[b]<<endl;
    int curr=b;
    vector<char> path;
    while(p[curr]!=-1){
      path.pb(act[curr]);
      curr=p[curr];
    }
    reverse(all(path));
    for(auto i:path){
      cout<<i;
    }
    cout<<endl;
  }
  return 0;
}
