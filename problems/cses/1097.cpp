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
const ll mod=1e9+7;
const int nmax=6e3;

int n;
ll s;
ll x[nmax];
ll dp[nmax][nmax];

int main(void){
  fastio;
  cin>>n;
  rep(i,1,n){
    cin>>x[i];
    s+=x[i];
  }
  rep(i,1,n)dp[i][i]=x[i];
  rep(i,1,n){ // r
    rrep(j,n,1){ // l
      if(i!=j){
        dp[i][j]=max(x[i]-dp[i-1][j],x[j]-dp[i][j+1]);
      }
    }
  }
  cout<<(s+dp[n][1])/2<<endl;
  return 0;
}
