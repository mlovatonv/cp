#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;

const ll mod=1e9+7;
const int nmax=1e5+100;

int n,m;
ll c[nmax];
vector<int> g1[nmax],g2[nmax];
ll ans1=0; // min money
ll ans2=1; // n of ways
bool vis[nmax];
vector<int> order,comp;

void dfs1(int v){
  vis[v]=true;
  for(auto i:g1[v]){
    if(!vis[i]){
      dfs1(i);
    }
  }
  order.pb(v);
}

void dfs2(int v){
  vis[v]=true;
  comp.pb(v);
  for(auto i:g2[v]){
    if(!vis[i]){
      dfs2(i);
    }
  }
}

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n)cin>>c[i];
  cin>>m;
  rep(i,0,m){
    int u,v;
    cin>>u>>v;
    g1[u-1].pb(v-1);
    g2[v-1].pb(u-1);
  }

  rep(i,0,n){
    if(!vis[i]){
      dfs1(i);
    }
  }

  memset(vis,0,n*sizeof(bool));

  rep(i,0,n){
    int v=order[n-1-i];
    if(!vis[v]){
      dfs2(v);

      ll minc=INT_MAX;
      ll nways=0;
      for(auto j:comp){
        minc=min(minc,c[j]);
      }
      for(auto j:comp){
        if(c[j]==minc){
          nways+=1;
        }
      }
      ans1+=minc;
      nways%=mod;
      ans2=(ans2*nways)%mod;

      comp.clear();
    }
  }

  cout<<ans1<<" "<<ans2<<endl;
  return 0;
}
