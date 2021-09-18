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

int n,m;
int cycle_start,cycle_end;
vector<vi> adj;
vector<int> parent;
vector<char> color;

bool dfs(int v) {
  color[v] = 1;
  for (int u : adj[v]) {
    if (color[u] == 0) {
      parent[u] = v;
      if (dfs(u))
        return true;
    } else if (color[u] == 1) {
      cycle_end = v;
      cycle_start = u;
      return true;
    }
  }
  color[v] = 2;
  return false;
}

void compress_cycles(){
  while(true){
    color.assign(n,0);
    parent.assign(n,-1);
    cycle_start=-1;

    for (int v = 0; v < n; v++) {
      if (color[v] == 0 && dfs(v))
        break;
    }

    if (cycle_start == -1){
      return;
    } else {
      vector<int> cycle;
      cycle.push_back(cycle_start);
      for (int v = cycle_end; v != cycle_start; v = parent[v])
        cycle.push_back(v);
      cycle.push_back(cycle_start);
      reverse(cycle.begin(), cycle.end());

      // merge cycle
      int node=cycle[0];
      set<int> s;
      ret(i,cycle){
        ret(j,g[i]){
          s.insert(j);
        }
      }
      rep(i,0,n){
        if(i!=node){
          ret(j,cycle){
            auto it=find(all(g[i]),j);
            if(it!=g[i].end())
              g[i].erase(it);
          }
          g[i].pb(node);
        }
      }
      copy(all(s),g[node].begin());
    }
  }
}

void solve(){
  cin>>n>>m;
  rep(i,1,m){
    int a,b;
    cin>>a>>b;
    --a,--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  compress_cycles();
}

int main(){
  fastio;
  solve();
  return 0;
}

