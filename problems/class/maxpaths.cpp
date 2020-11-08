#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define vi vector<int>
using namespace std;

// 10/08/2020

const int N=2e5;
vi d1(N),d2(N),d3(N);

void dfs1(int x,int p){
  dist1[x]=dist3[x]=0;
  for(auto u:adj[x]){
    if(u!=p){
      dfs1(u,x);
      if(dist[u]+1>dist1[x]){
        dist3[x]=dist1[x];
        dist1[x]=dist[u]+1;
      }
    }
  }
}

void dfs2(int x,int p){
  for(auto u:adj[x]){
    if(u!=p){
      if(sgte[])
    }
  }
}

int main(void){
  fastio;
  dfs1(1,1);
  dfs2(1,1);
  return 0;
}
