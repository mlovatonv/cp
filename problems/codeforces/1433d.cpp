#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
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

int t,n,x;

void solve(){
  cin>>n;
  vi gang(n);
  vi vis(n);
  vector<vi> graph(n);
  rep(i,0,n)cin>>gang[i];

  queue<int> q;
  q.push(0);
  vis[0]=1;
  while(!q.empty()){
    x=q.front();
    q.pop();
    rep(i,0,n)
      if(!vis[i]&&gang[x]!=gang[i]){
        vis[i]=1;
        graph[x].pb(i);
        q.push(i); 
      }
  }

  rep(i,0,n)
    if(!vis[i]){
      cout<<"NO"<<endl;
      return;
    }

  cout<<"YES"<<endl;
  rep(i,0,n)ret(j,graph[i])cout<<i+1<<" "<<j+1<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

