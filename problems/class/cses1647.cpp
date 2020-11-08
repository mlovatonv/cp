#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
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
const int nmax=2e5+1;
const int lognmax=(int)log2(2e5)+1;

int n,q,a,b,x;
int m[lognmax][nmax];

int main(void){
  fastio;
  cin>>n>>q;
  rep(i,1,n)cin>>m[0][i];
  int imax=log2(n);
  rep(i,1,imax){
    int jmax=n-(int)pow(2,i)+1;
    rep(j,1,jmax)m[i][j]=min(m[i-1][j],m[i-1][j+(int)pow(2,i-1)]);
  }
  //rep(i,0,imax){
  //  rep(j,1,n)
  //    cout<<m[i][j]<<' ';
  //  cout<<endl;
  //}
  while(q--){
    cin>>a>>b;
    int i=(int)log2(b-a+1);
    int j=b-(int)pow(2,i)+1;
    //cout<<"i="<<i<<" j="<<j<<endl;
    cout<<min(m[i][a],m[i][j])<<endl;
  }
  return 0;
}
