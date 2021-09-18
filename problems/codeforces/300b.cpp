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
  vector<vector<int>> g(n+1),comp;
  vector<int> vis(n+1);
  rep(i,1,m){
    int a,b;
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }

  function<void(int)> dfs=[&](int x){
    vis[x]=1;
    comp.back().pb(x);
    ret(j,g[x]){
      if(!vis[j]){
        dfs(j);   
      }    
    }
  };
  rep(i,1,n){
    if(!vis[i]){
      comp.pb(vector<int>());
      dfs(i);
    }
  }

  ret(i,comp){
    if(i.size()>3){
      cout<<-1<<endl;
      return;
    }
    if(i.size()==2){
      ret(j,comp){
        if(j.size()==1){
          i.pb(j[0]);
          j.clear();
          break;
        }
      }
      if(i.size()==2){
        cout<<-1<<endl;
        return;
      }
    }
  }
  ret(i,comp){
    if(i.size()==1){
      dbg(i);
      int t=0;
      ret(j,comp){
        if(j.size()==1&&i[0]!=j[0]){
          dbg(j);
          ++t;
          i.pb(j[0]);
          j.clear();
        }
        if(t==2)break;
      }
      if(t!=2){
        cout<<-1<<endl;
        return;
      }
      dbg(i);
    }
  }

  dbg(comp);
  ret(i,comp){
    if(i.size()==3){
      cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;     
    }
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

