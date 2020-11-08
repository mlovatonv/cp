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
#define get(a,b) (a.find(b)!=a.end())
typedef long long ll;
using namespace std;
const int MOD=1e9+7;
const int N=100;
const int M=1e6+1;
const int INF=1e9;

int n,x;
int c[N],dp[M];

int main(void){
  fastio;
  cin>>n>>x;
  rep(i,0,n)cin>>c[i];
  rep(i,1,x+1){
    dp[i]=INF;
    rep(j,0,n)if(i-c[j]>=0)dp[i]=min(dp[i],dp[i-c[j]]+1);
  }
  cout<<(dp[x]==INF?-1:dp[x])<<endl;
  return 0;
}
