#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=501;
const ll inf=1e18;

ll dp[nmax][nmax];
int a,b;

int main(void){
  fastio;
  rep(i,0,nmax)rep(j,0,nmax)dp[i][j]=inf;
  rep(i,1,nmax)dp[i][i]=0;
  rep(i,1,nmax){
    rep(j,1,nmax){
      if(i!=j){
        rep(k,1,i){
          dp[i][j]=min(dp[i][j],dp[i-k][j]+dp[k][j]);
        }
        rep(k,1,j){
          dp[i][j]=min(dp[i][j],dp[i][j-k]+dp[i][k]);
        }
        ++dp[i][j];
      }
    }
  }
  cin>>a>>b;
  cout<<dp[a][b]<<endl;
  return 0;
}
