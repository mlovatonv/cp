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
const int nmax=1e3+1;

int n;
char c;
int dp[nmax][nmax];

int main(void){
  fastio;
  cin>>n;
  cin>>c;
  dp[1][1]=c!='*';
  rep(i,2,n){
    cin>>c;
    if(c!='*')dp[1][i]=dp[1][i-1];
  }
  rep(i,2,n)
    rep(j,1,n){
      cin>>c;
      if(c!='*')dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%mod;
    }
  cout<<dp[n][n]<<endl;
  return 0;
}
