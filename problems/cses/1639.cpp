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
const int nmax=5005;

string n,m;
int ns,ms;
int dp[nmax][nmax];

int main(void){
  fastio;
  cin>>n;
  cin>>m;
  ns=n.size();
  ms=m.size();
  rep(i,1,ns)dp[i][0]=i;
  rep(i,1,ms)dp[0][i]=i;
  rep(i,1,ns){
    rep(j,1,ms){
      dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+(n[i-1]!=m[j-1])});
    }
  }
  cout<<dp[ns][ms]<<endl;
  return 0;
}
