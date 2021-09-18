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

int n,m,x;
vector<string> ss;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

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

bool find_cycle() {
    color.assign(x,0);
    parent.assign(x,-1);
    cycle_start=-1;

    for (int v = 0; v < x; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        return false;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        dbg(cycle);
        return len(cycle)>=4;
    }
}

int get_id(int i,int j){
  return n*i+j;
}

bool foo(char c){
  adj.assign(x,vector<int>(0));

  // form graph
  int id1,id2;
  rep(i,0,n-1){
    rep(j,0,m-1){
      if(ss[i][j]==c){
        id1=get_id(i,j);
        // check up
        if(0<i&&ss[i-1][j]==c){
          id2=get_id(i-1,j);
          adj[id1].pb(id2);
        }
        // check down
        if(i<n-1&&ss[i+1][j]==c){
          id2=get_id(i+1,j);
          adj[id1].pb(id2); 
        }
        // check left
        if(0<j&&ss[i][j-1]==c){
          id2=get_id(i,j-1);
          adj[id1].pb(id2);  
        }
        // check right
        if(j<m-1&&ss[i][j+1]==c){
          id2=get_id(i,j+1);
          adj[id1].pb(id2);  
        }
      }
    }
  }

  return find_cycle();
}

void solve(){
  cin>>n>>m;
  x=n*m;
  rep(i,0,n-1){
    string s;
    cin>>s;
    ss.pb(s);
  }

  rep(c,'A','Z'){
    if(foo(c)){
      cout<<"Yes"<<endl;
      return;
    }
  }

  cout<<"No"<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

