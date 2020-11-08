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
int n,x,ai,l,r,s;
pi a[N];

int main(void){
  fastio;
  cin>>n>>x;
  r=n-1;
  rep(i,0,n){
    cin>>ai;
    a[i]=mp(ai,i);
  }
  sort(a,a+n);
  while(l<r){
    s=a[l].fi+a[r].fi;
    if(s>x)--r;
    else if(s<x)++l;
    else{
      cout<<a[l].se+1<<' '<<a[r].se+1<<endl;
      return 0;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}
