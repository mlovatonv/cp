#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

const int N=2e5,K=1e9+5;
int n,ans;
int k[N];
map<int,bool> vis;

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n)cin>>k[i];
  int j=0;
  rep(i,0,n){
    while(j<n&&!vis[k[j]]){
      vis[k[j]]=true;
      ++j;
    }
    vis[k[i]]=false;
    ans=max(ans,j-i);
  }
  cout<<ans<<endl;
  return 0;
}
