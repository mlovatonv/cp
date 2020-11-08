/*
 * Time complexity: O(m*2^n)
 * Explanation: All possible combinations are checked m times.
 *
 * Space complexity: O(m*2^n)
 * Explanation: A dp matrix is used to save the minimum of 2^n combinations
 * with m first routers. 
 *
 * Idea: Minimize the price for the combinations of routers and computers by
 * constructing an optimum path in the dp matrix.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define vi vector<int>
#define rep(i,s,e) for(int i=s;i<e;++i)
#define fi first
#define se second
using namespace std;

const int N=12+5,N2=4096+5,M=1e3+5,MAX_P=1e9;
ll n,m,ans=MAX_P;
/* p->price per router, c->connections per router */
ll p[M],c[M],dp[M][N2];

int main(void){
  fastio;
  cin>>n>>m;
  rep(i,0,m){
    ll j,aux;
    cin>>p[i]>>j;
    rep(k,0,j){
      cin>>aux;
      c[i]|=1<<(aux-1);
    }
  }
  rep(i,0,m+1)rep(j,0,1<<n)dp[i][j]=MAX_P;
  dp[0][0]=0;
  rep(i,0,m){
    if(i>0){
      rep(j,0,1<<n){
        dp[i][j]=min(dp[i][j],dp[i-1][j]);
      }
    }
    rep(j,0,1<<n){
      dp[i+1][j|c[i]]=min({dp[i+1][j|c[i]],dp[i][j|c[i]],dp[i][j]+p[i]});
      //cout<<"i="<<i<<" j="<<j<<" c[i]="<<c[i]<<" p[i]="<<p[i]<<" min1="<<dp[i+1][j|c[i]]<<" min2="<<dp[i][j|c[i]]<<" min3="<<dp[i][j]+p[i]<<" dp="<<dp[i+1][j|c[i]]<<endl;
    }
  }
  rep(i,0,m+1)ans=min(ans,dp[i][(1<<n)-1]);
  ans=ans>=MAX_P?-1:ans;
  cout<<ans<<endl;
  return 0;
}
