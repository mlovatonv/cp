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

const int nmax=15;
int mat[nmax][nmax];
int ans;
int t,n,m;

void debug(){
  rep(i,0,n){
    rep(j,0,m)
      cout<<mat[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
}

void solve(){
  cin>>n>>m;
  ans=0;
  rep(i,0,n)rep(j,0,m){
    cin>>mat[i][j];
    ans+=mat[i][j];
  }
  rep(i,0,n){
    rep(j,0,m){
      if(i+1<n){
        if(mat[i][j]+mat[i+1][j]<mat[i][j]*-1+mat[i+1][j]*-1){
          mat[i][j]*=-1;
        }
      }
      if(j+1<m) 
    }
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t){
    solve();
  }
  return 0;
}
