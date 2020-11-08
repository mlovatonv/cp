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
const int MOD=1e9+7;
const int N=1e6+1;

ll dp[N];
ll n;

void build(){
  ll acc=dp[0]=1;
  rep(i,1,7)dp[i]=acc,acc*=2;
  rep(i,7,N){
    rep(j,1,7)dp[i]+=dp[i-j]%MOD;
    dp[i]%=MOD;
  }
}

int main(void){
  fastio;
  cin>>n;
  build();
  cout<<dp[n]<<endl;
  return 0;
}
