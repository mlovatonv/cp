#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
#define ret(i,c) for(auto &i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ll=long long;
using vi=vector<int>;


void solve(){
  int n,m;
  cin>>n>>m;
  vector<vector<char>> mx(n+2,vector<char>(m+2,'#'));
  rep(i,1,n)rep(j,1,m)cin>>mx[i][j];
  int g=0,b=0;
  rep(i,1,n)rep(j,1,m)if(mx[i][j]=='G')++g;
  rep(i,1,n)rep(j,1,m){
    if(mx[i][j]=='B'){
      ++b;
      mx[i][j-1]='#';
      if(mx[i][j+1]!='B')mx[i][j+1]='#';
      mx[i-1][j]='#';
      if(mx[i+1][j]!='B')mx[i+1][j]='#';
    }
  }

  int g2=0;
  vector<vi> vis(n+2,vi(m+2));
  function<void(int,int)> dfs=[&](int i,int j){
    vis[i][j]=1;
    if(mx[i][j]=='G')++g2;
    if(!vis[i][j-1]&&(mx[i][j-1]=='.'||mx[i][j-1]=='G')){
      dfs(i,j-1);
    }
    if(!vis[i][j+1]&&(mx[i][j+1]=='.'||mx[i][j+1]=='G')){
      dfs(i,j+1);
    }
    if(!vis[i-1][j]&&(mx[i-1][j]=='.'||mx[i-1][j]=='G')){
      dfs(i-1,j);
    }
    if(!vis[i+1][j]&&(mx[i+1][j]=='.'||mx[i+1][j]=='G')){
      dfs(i+1,j);
    }
  };

  if(mx[n][m]=='.'||mx[n][m]=='G'){
    dfs(n,m);
  }elif(mx[n][m]=='B'){
    g2=-1;
  }
  
  dbg(g);
  dbg(g2);

  if(g2==g)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)
  solve();
  return 0;
}

