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

const int nmax=1e5+5,mmax=2e5+5;
int n,m;
vi adj[nmax];
int s[nmax];
vi topo;

void dfs(int x){
  s[x]=1;
  ret(i,adj[x]){
    if(s[i]==0)dfs(i);
    elif(s[i]==1){
      cout<<"IMPOSSIBLE"<<endl;
      exit(0);
    }
  }
  s[x]=2;
  topo.pb(x);
}

int main(){
  fastio;
  cin>>n>>m;
  rep(i,1,m){
    int a,b;
    cin>>a>>b;
    adj[a].pb(b);
  }
  rep(i,1,n)if(s[i]==0)dfs(i);
  reverse(all(topo));
  ret(i,topo)cout<<i<<" ";
  cout<<endl;
  return 0;
}

