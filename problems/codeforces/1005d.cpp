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
const int mod=3;
const int nmax=2e5+100;

string s;
int n,m;
int dp[nmax],last[mod];

int main(void){
  fastio;
  cin>>s;
  n=s.size();
  rep(i,1,mod)last[i]=-1;
  rep(i,1,n){
    dp[i]=dp[i-1];
    m=(m+s[i-1]-'0')%mod;
    if(last[m]!=-1)dp[i]=max(dp[i],dp[last[m]]+1);
    last[m]=i;
  }
  cout<<dp[n]<<endl;
  return 0;
}
