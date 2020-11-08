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
const int nmax=100;
const int xmax=1e6+1;

int n,x;
ll c[nmax],dp[xmax],aux;

int main(void){
  fastio;
  cin>>n>>x;
  rep(i,0,n)cin>>c[i];
  dp[0]=1;
  rep(i,1,x+1){
    rep(j,0,n)if(i-c[j]>=0)dp[i]+=dp[i-c[j]]%mod;
    dp[i]%=mod;
  }
  cout<<dp[x]<<endl;
  return 0;
}
