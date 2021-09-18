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
  int n;
  cin>>n;
  vector<vector<int>> g(n+1);
  rep(i,1,n){
    int m;
    cin>>m;
    rep(j,1,m){
      int u;
      cin>>u;
      g[u].pb(i); 
    }
  }

  vector<int> color(n+1);
  bool cycle=false;
  function<void(int)> dfs1=[&](int x){
    color[x]=1;
    ret(i,g[x]){
      if(color[i]==1){
        cycle=true;
      }elif(color[i]==0){
        dfs1(i);     
      }
    }
    color[x]=2;
  };
  rep(i,1,n){
    if(!color[i]){
      dfs1(i);    
    }
  }
  if(cycle){
    cout<<-1<<endl;
    return;
  }

  color.assign(n+1,0);
  function<pair<int,int>(int)> dfs2=[&](int x){
    color[x]=1;
    pair<int,int> y={INT_MAX,-1};
    ret(i,g[x]){
      if(!color[x]){
        pair<int,int> p=dfs2(i);
        if(y.se<p.se){
          y.se=p.se;
        }
        if(p.fi<y.fi){
          y.fi=p.fi;
        }     
      }
    }
    if(y.fi==INT_MAX){
      y.fi=x;
      y.se=0;
    }

    if(x>y.fi){
      ++y.se; 
    }else{
      y.fi=x;
    }

    dbg(x);
    dbg(y);
    return y;
  };

  int ans=0;
  rep(i,1,n){
    if(!color[i]){
      int ans2=dfs2(i).se;
      dbg(ans2);
      ans=max(ans,ans2);
    }
  }
 
  cout<<ans+1<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)
  solve();
  return 0;
}

