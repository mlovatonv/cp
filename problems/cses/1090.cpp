#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;++i)
#define fi first
#define se second
using namespace std;

const int N=2e5+5;
ll x;
ll p[N];
int n,l,r,ans;

int main(void){
  fastio;
  cin>>n>>x;
  rep(i,0,n)cin>>p[i];
  sort(p,p+n);
  r=n;
  rep(i,1,n)if(p[0]+p[i]>x){r=i;break;}
  if(r!=n)ans+=n-r;
  --r;
  while(l<r){
    if(p[l]+p[r]>x){
      ++ans;
      --r;
    }
    else{
      ++ans;
      --r;
      ++l;
    }
  }
  if(l==r)++ans;
  cout<<ans<<endl;
  return 0;
}
