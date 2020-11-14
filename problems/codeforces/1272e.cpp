#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;

const int nmax=2e5+10;
int n;
int a[nmax];
vector<int> g2[nmax];
int ans[nmax];

void bfs(int x){
  g2[n+1].clear();
  rep(i,1,n){
    if(a[i]%2==x){
      g2[n+1].pb(i);
    }
  }

  queue<int> q;
  vector<int> d(n+2,0);
  vector<bool> vis(n+2,false);

  q.push(n+1);
  vis[n+1]=true;

  while(!q.empty()){
    int f=q.front();
    q.pop();
    for(int i:g2[f]){
      if(!vis[i]){
        vis[i]=true;
        q.push(i);
        d[i]=d[f]+1;
      }
    }
  }

  rep(i,1,n){
    if(a[i]%2!=x){
      ans[i]=d[i]-1;
    }
  }
}

int main(void){
  fastio;
  cin>>n;
  rep(i,1,n)cin>>a[i];
  rep(i,1,n){
    if(i+a[i]<=n){
      g2[i+a[i]].pb(i);
    }
    if(1<=i-a[i]){
      g2[i-a[i]].pb(i);
    }
  }

  bfs(0);
  bfs(1);

  rep(i,1,n)cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}
