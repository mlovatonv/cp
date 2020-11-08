#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

const int N=2e5;
int n;
ll x[N],k,l,m,r=2e14;

bool p(ll pt){
  ll s=0,d=0;
  rep(i,0,n){
    if(s+x[i]>pt){
      ++d;
      s=0;
    }
    s+=x[i];
  }
  return d<k;
}

int main(void){
  fastio;
  cin>>n>>k;
  rep(i,0,n){
    cin>>x[i];
    l=max(l,x[i]);
  }
  while(l<r){
    m=l+(r-l)/2;
    if(p(m))r=m;
    else l=m+1;
  }
  cout<<l<<endl;
  return 0;
}
