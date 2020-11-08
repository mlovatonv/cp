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

const int N=5000;
int n,x,ai,l,r,s;
pi a[N];

int main(void){
  fastio;
  cin>>n>>x;
  rep(i,0,n){
    cin>>ai;
    a[i]=mp(ai,i);
  }
  sort(a,a+n);
  rep(i,1,n-1){
    l=0;
    r=n-1;
    while(l<r&&l<i&&i<r){
      s=a[l].fi+a[i].fi+a[r].fi;
      if(s<x)++l;
      elif(s>x)--r;
      else{
        cout<<a[l].se+1<<' '<<a[i].se+1<<' '<<a[r].se+1<<endl;
        return 0;
      }
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}
