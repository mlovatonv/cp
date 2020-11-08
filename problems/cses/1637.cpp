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
const int nmax=1e6+1;

int n;
int dp[nmax];

void build(){
  rep(i,1,n){
    string s=to_string(i);
    dp[i]=INT_MAX;
    for(auto &c:s)dp[i]=min(dp[i],dp[i-(c-'0')]+1);
  }
}

int main(void){
  fastio;
  cin>>n;
  build();
  cout<<dp[n]<<endl;
  return 0;
}
