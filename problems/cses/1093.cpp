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
const ll mod=1e9+7;
const int nmax=5e2+1;
const int xmax=1e5;

int n,x,y;
int dp[nmax][xmax];

int main(void){
  fastio;
  cin>>n;
  x=(n*(n+1))/2;
  if(x%2!=0){
    cout<<0<<endl;
    return 0;
  }
  x/=2;
  dp[0][0]=1;
  rep(i,1,n-1){
    rep(j,0,x){
      dp[i][j]=dp[i-1][j];
      if(j-i>=0){
        dp[i][j]=(dp[i][j]+dp[i-1][j-i])%mod;
      }
    }
  }
  cout<<dp[n-1][x]<<endl;
  return 0;
}
