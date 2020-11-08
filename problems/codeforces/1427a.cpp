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

const int N=55;
int t,n,s,sp,sn;
int a[N];

void solve(){
  cin>>n;
  s=0;
  sp=0;
  sn=0;
  rep(i,0,n){
    cin>>a[i];
    if(a[i]>0)sp+=a[i];
    else sn+=a[i];
  }
  if(abs(sn)>sp){
    sort(a,a+n);
  }else{
    sort(a,a+n,greater<int>());
  }
  rep(i,0,n){
    s+=a[i];
    if(s==0){
      cout<<"NO"<<endl;
      return;
    }
  }
  cout<<"YES"<<endl;
  rep(i,0,n)cout<<a[i]<<' ';
  cout<<endl;
}

int main(void){
  fastio;
  cin>>t;
  while(t--)solve();
  return 0;
}
