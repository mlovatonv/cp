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
const int nmax=100+1;
const int xmax=1e6+1;

int n,x;
int c[nmax],dp[nmax][xmax];

int main(void){
  fastio;
  cin>>n>>x;
  rep(i,1,n)cin>>c[i];
  dp[0][0]=1;
  rep(i,1,n)
    rep(j,0,x){
      dp[i][j]=dp[i-1][j];
      if(j-c[i]>=0)dp[i][j]+=dp[i][j-c[i]]%mod;
      dp[i][j]%=mod;
    }
  cout<<dp[n][x]<<endl;
  return 0;
}

