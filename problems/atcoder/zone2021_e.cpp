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
  int r,c;
  cin>>r>>c;
  dbg(r);
  dbg(c);
  vector<vi> aa(r+1,vi(c)),bb(r,vi(c+1));
  rep(i,1,r){
    rep(j,1,c-1){
      cin>>aa[i][j];
    }
  }
  dbg(aa);
  rep(i,1,r-1){
    rep(j,1,c){
      cin>>bb[i][j];
    }
  }
  dbg("start");

  auto row_col=[&](int i)->pair<int,int>{return {(i-1)/c+1,(i-1)%c+1};};
  int n=(r+1)*(c+1);
  vector<vi> adj(n,vi(n));
  rep(i,1,n){
    auto rc=row_col(i);
    if(rc.se<c){
      adj[i][i+1]=min(
          adj[i][i+1],
          aa[rc.fi][rc.se]
      );
    }
    if(1<rc.se){
      adj[i][i-1]=min(
          adj[i][i-1],
          aa[rc.fi][rc.se-1]
      ); 
    }
    if(rc.fi<r){
      adj[i][i+c]=min(
          adj[i][i+c], 
          bb[rc.fi][rc.se]
      );
    }
    rep(j,1,r-1){
      if(rc.fi-j>0){
        adj[i][i-j*c]=min(
            adj[i][i-j*c],
            1+j
        );
      }
    }
  }

  const int INF = 1000000000;
  vi d(n,INF),p(n,-1),u(n,0);
  d[1] = 0;
  rep(i,1,n){
    int v = -1;
    rep(j,1,n){
      if(!u[j]&&(v==-1||d[j]<d[v]))
        v=j;
    }

    if (d[v] == INF)
        break;

    u[v] = true;
    rep(to,1,n){
      int cost=adj[v][to];
      if(d[v]+cost<d[to]){
        d[to]=d[v]+cost;
        p[to]=v;
      }
    }
  }

  cout<<d[r*c]<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

