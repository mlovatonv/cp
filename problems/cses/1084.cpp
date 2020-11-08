#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;++i)
#define fi first
#define se second
using namespace std;

const int N=2e5+5;
ll n,m,k,j,cnt;
ll a[N],b[N];

int main(void){
  fastio;
  cin>>n>>m>>k;
  rep(i,0,n)cin>>a[i];
  rep(i,0,m)cin>>b[i];
  sort(a,a+n);
  sort(b,b+m);
  int j=0;
  rep(i,0,n){
    //cout<<a[i]<<' '<<b[j]<<endl;
    if(a[i]-k>b[m-1]||j==m)break;
    if(a[i]-k<=b[j]&&b[j]<=a[i]+k){++j;++cnt;}
    else if (a[i]-k>b[j]){
      while(j!=m&&a[i]-k>b[j])++j;
      if(j!=m&&b[j]<=a[i]+k){++j;++cnt;}
    }
  }
  cout<<cnt<<endl;
  return 0;
}
