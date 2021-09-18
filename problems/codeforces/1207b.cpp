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
#define ret(i,c) for(auto i:c)
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
  vector<vi> mat(n,vi(m)),vis(n,vi(m));
  rep(i,0,n-1){
    rep(j,0,m-1){
      cin>>mat[i][j];
    }
  }
  vector<pair<int,int>> ans;
  rep(i,0,n-2){
    rep(j,0,m-2){
      if(mat[i][j]){
        if(mat[i+1][j]&&mat[i][j+1]&&mat[i+1][j+1]){
          vis[i+1][j]=vis[i][j+1]=vis[i+1][j+1]=1;
          ans.pb({i+1,j+1});
        }elif(!vis[i][j]){
          cout<<-1<<endl;
          return;
        }
        vis[i][j]=1;
      }
    }
  }
  rep(i,0,n-1){
    rep(j,0,m-1){
      if(mat[i][j]&&!vis[i][j]){
        cout<<-1<<endl;
        return;
      }
    }
  }
  cout<<len(ans)<<endl;
  ret(i,ans){
    cout<<i.fi<<" "<<i.se<<endl;
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

