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
const int nmax=1e3+1,xmax=1e5+1;

int n,x;
int h[nmax],s[nmax],dp[nmax][xmax];

int main(void){
  fastio;
  cin>>n>>x;
  rep(i,1,n)cin>>h[i];
  rep(i,1,n)cin>>s[i];
  rep(i,1,n)
    rep(j,1,x){
      dp[i][j]=dp[i-1][j];
      if(j-h[i]>=0)dp[i][j]=max(dp[i][j],dp[i-1][j-h[i]]+s[i]);
    }
  cout<<dp[n][x]<<endl;
  return 0;
}
