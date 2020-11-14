#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;

const int nmax=105;
int n,m;
int a[nmax],b[nmax];
int dp[nmax][nmax];
pi p[nmax][nmax];
vector<int> s;

int main(void){
  fastio;
  cin>>n>>m;
  rep(i,1,n)cin>>a[i];
  rep(i,1,m)cin>>b[i];
  rep(i,1,n){
    rep(j,1,m){
      if(a[i]==b[j]){
        dp[i][j]=dp[i-1][j-1]+1;
        p[i][j]={i-1,j-1};
      }elif(dp[i-1][j]<dp[i][j-1]){
        dp[i][j]=dp[i][j-1];
        p[i][j]={i,j-1};
      }else{
        dp[i][j]=dp[i-1][j];
        p[i][j]={i-1,j};
      }
    }
  }
  int curr=dp[n][m];
  rrep(i,n,1){
    rrep(j,m,1){
      if(dp[i-1][j-1]==curr-1&&p[i][j]==mp(i-1,j-1)){
        s.pb(a[i]);
        --curr;
      } 
    }
  }
  reverse(all(s));
  for(auto i:s)cout<<i<<" ";
  cout<<endl;
  return 0;
}

