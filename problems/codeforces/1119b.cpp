#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;++i)
#define rep2(i,s,e) for(int i=s;i<e;i+=2)
#define fi first
#define se second
using namespace std;

const int N=1e3+5;
ll n,h,l,r,mid;
ll a[N],aux[N];

bool p(ll pos){
  copy(a,a+pos,aux);
  sort(aux,aux+pos,greater<ll>());
  ll k=0;
  rep2(i,0,pos){
    k+=aux[i]; 
  }
  return k<=h;
}

int main(void){
  fastio;
  cin>>n>>h;
  rep(i,0,n)cin>>a[i];
  l=1;
  r=n;
  while(l<r){
    mid=l+(r-l+1)/2;
    if(p(mid))l=mid;
    else r=mid-1;
  }
  cout<<r<<endl;
  return 0;
}
