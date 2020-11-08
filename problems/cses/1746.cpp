#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=1e5+1,mmax=1e2+1;

int n,m,x,px;
ll dp[nmax][mmax];

int main(void){
  fastio;
  cin>>n>>m;
  cin>>x;
  if(x==0)rep(i,1,m)dp[1][i]=1;
  else dp[1][x]=1;
  rep(i,2,n){
    cin>>x;
    if(x==0){
      rep(j,1,m){
        dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
        dp[i][j]%=mod;  
      }
    }else{
      dp[i][x]=dp[i-1][x-1]+dp[i-1][x]+dp[i-1][x+1];
      dp[i][x]%=mod;
    }
  }
  if(x==0){
    ll ans=0;
    rep(i,1,m)ans+=dp[n][i];
    ans%=mod;
    cout<<ans<<endl;
  }else cout<<dp[n][x]<<endl;
  return 0;
}
