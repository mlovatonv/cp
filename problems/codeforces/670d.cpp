#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;++i)
#define fi first
#define se second
using namespace std;

const int N=1e5+5;
ll n,k,l,r,mid;
ll a[N],b[N];

bool p(ll cookies){
  ll localK=k;
  rep(i,0,n)
    if(b[i]/a[i]<cookies){
      localK-=cookies*a[i]-b[i];
      if(localK<0)return false;
    }
  return true;
}

int main(void){
  fastio;
  cin>>n>>k;
  rep(i,0,n)cin>>a[i];
  rep(i,0,n)cin>>b[i];
  l=0;
  r=(b[0]+k)/a[0];
  while(l<r){
    mid=l+(r-l+1)/2;
    if(p(mid))l=mid;
    else r=mid-1;
  }
  cout<<r<<endl;
  return 0;
}
