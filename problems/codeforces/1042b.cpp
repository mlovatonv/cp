#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

const int N=1e3+5,M=8,F=1e9;
int n;
ll ans=F;
ll c[N],v[N],dp[N][M];
string s;

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n){
    cin>>c[i]>>s;
    for(auto j:s){
      if(j=='A') v[i]|=1<<0;
      elif(j=='B') v[i]|=1<<1;
      else v[i]|=1<<2;
    }
  }
  rep(i,0,n+1)rep(j,0,M)dp[i][j]=F;
  dp[0][0]=0;
  rep(i,0,n){
    if(i>0){
      rep(j,0,M)dp[i][j]=min(dp[i][j],dp[i-1][j]);
    }
    rep(j,0,M){
      dp[i+1][j|v[i]]=min({
          dp[i+1][j|v[i]],
          dp[i][j]+c[i],
          dp[i][j|v[i]]
      });
    }
  }
  rep(i,1,n+1)ans=min(ans,dp[i][M-1]);
  if(ans>=F)cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}
