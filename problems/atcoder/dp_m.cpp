#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ll=long long;
using vi=vector<int>;

const ll mod=1e9+7;
const int nmax=1e2+10,mmax=1e5+10;
int n,m;
int a[nmax];
int pre[nmax];
ll dp[nmax][mmax];

int main(){
  fastio;
  cin>>n>>m;
  rep(i,1,n){
    cin>>a[i];
    pre[i]=pre[i-1]+a[i];
  }
  rep(i,0,n)dp[0][i]=1;
  rep(i,1,n){
    dp[i][0]=1;
    cout<<"dp["<<i<<"][0]="<<dp[i][0]<<endl; 
    rep(j,1,m){
      dp[i][j]=dp[i][j-1]+dp[i-1][j];
      if(j-a[i]>=0)dp[i][j]-=dp[i-1][j-a[i]];
      //if(j<=pre[i])dp[i][j]=(dp[i][j]+dp[i-1][min(m,pre[i]-j)])%mod;
      cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
    }
  }
  cout<<dp[n][m]-dp[n][m-1]<<endl;
  return 0;
}

