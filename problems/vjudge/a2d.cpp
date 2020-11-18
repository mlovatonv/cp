#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
const int nmax=1e3+5;

ll dp[nmax],v[nmax];
int n,c;
int w[nmax];
int aux[nmax][nmax];
int temp;
ll temp1,temp2;
ll ans;

int main(){
  fastio;
  cin>>n>>c;
  rep(i,0,n)cin>>w[i];
  rep(i,0,n)cin>>v[i];
  rep(i,1,c+1){
    rep(j,0,n){
      temp=i-w[j];
      if(0<=temp){
        temp1=dp[i];
        temp2=v[j];
        rep(k,0,aux[temp][j])temp2/=2LL;
        if(temp2==0)continue;
        dp[i]=max(dp[i],dp[temp]+temp2);
        if(dp[i]!=temp1){
          rep(k,0,n)aux[i][k]=aux[temp][k];
          ++aux[i][j];
        }
      }
    }
    cout<<"dp["<<i<<"]="<<dp[i]<<" aux=";
    rep(k,0,n)cout<<aux[i][k]<<" ";
    cout<<endl;
  }
  rep(i,1,c+1)ans=max(ans,dp[i]);
  cout<<ans<<endl;
  return 0;
}
