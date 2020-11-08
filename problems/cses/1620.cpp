#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

const int N=2e5;
int n;
ll t,r,l,mid,mink=LLONG_MAX;
ll k[N];

bool p(ll x){
  ll acc=0;
  rep(i,0,n)acc+=x/k[i];
  return acc>=t;
}

int main(void){
  fastio;
  cin>>n>>t;
  rep(i,0,n){
    cin>>k[i];
    mink=min(mink,k[i]);
  }
  r=mink*t;
  while(l<r){
    mid=l+(r-l)/2;
    if(p(mid))r=mid;
    else l=mid+1;
  }
  cout<<r<<endl;
  return 0;
}
