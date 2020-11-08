#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define pb push_back
using namespace std;

// funciona porque seleccionamos un l que siempre da

const int N=2e5,L=15;
int anc[N][L];
vector<int> adj[N];
int n,q,l,e,x,k,next;

void dfs(int a,int p){
  anc[a][0]=p;
  rep(i,1,l+1){
    int y=anc[a][i-1];
    anc[a][i]=anc[y][i-1];
  }
  for(auto i:adj[a])dfs(i,a);
}

int query(int a, int b){
  int t=log2(k);
  int ans=a;
  rep(i,0,t+1)if((1<<i)&k)ans=anc[ans][i];
  return ans>0?ans:-1;
}

int main(void){
  fastio;
  cin>>n>>q;
  l=log2(n-1);
  rep(i,2,n+1){
    cin>>e;
    adj[e].pb(i);
  }
  dfs(1,0);
  while(q--){
    cin>>x>>k;
    cout<<query(x,k)<<endl;
  }
  return 0;
}
