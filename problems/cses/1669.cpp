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
int c[nmax];
int cs,ce;

bool dfs(int x,int xp){
  c[x]=1;
  ret(i,adj[x]){
    if(i==xp)continue;
    if(c[i]==0){
      p[i]=x;
      if(dfs(i,x))return true;
    }elif(c[i]==1){
      cs=i;
      ce=x;
      return true;
    }
  }
  c[x]=2;
  return false;
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
  rep(i,1,n+1)if(c[i]==0&&dfs(i,p[i]))break;
  if(cs==0)cout<<"IMPOSSIBLE\n";
  else{
    vi cycle;
    for(int x=ce;x!=cs;x=p[x])cycle.pb(x);
    cycle.pb(cs);
    reverse(all(cycle));
    cout<<cycle.size()+1<<'\n';
    ret(i,cycle)cout<<i<<" ";
    cout<<cs<<'\n';
  }
  return 0;
}
