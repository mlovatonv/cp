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
const int nmax=1e2+1,xmax=1e5+1;

int n,x,cnt;
int c[nmax];
bool dp[nmax][xmax];

int main(void){
  fastio;
  cin>>n;
  rep(i,1,n){
    cin>>c[i];
    x+=c[i];
  }
  dp[0][0]=true;
  rep(i,1,n){
    rep(j,0,x){
      dp[i][j]=dp[i-1][j];
      if(j-c[i]>=0){
        dp[i][j]|=dp[i-1][j-c[i]];
      }
    }
  }
  rep(i,1,x)if(dp[n][i])++cnt;
  cout<<cnt<<endl;
  rep(i,1,x)if(dp[n][i])cout<<i<<" ";
  cout<<endl;
  return 0;
}
