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

const int N=1000;
int n,x;
ll a[N];
map<ll,pi> m;

int main(void){
  fastio;
  cin>>n>>x;
  rep(i,0,n)cin>>a[i];
  if(n<4){cout<<"IMPOSSIBLE"<<endl;return 0;}
  rep(i,0,n)rep(j,i+1,n)m[a[i]+a[j]]=mp(i,j);
  rep(i,0,n)rep(j,i+1,n){
    if(m.find(x-a[i]-a[j])!=m.end()){
      pi p=m[x-a[i]-a[j]];
      if(p.fi!=i&&p.fi!=j&&p.se!=i&&p.se!=j){
        cout<<i+1<<' '<<j+1<<' '<<p.fi+1<<' '<<p.se+1<<endl;
        return 0;
      }
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}
