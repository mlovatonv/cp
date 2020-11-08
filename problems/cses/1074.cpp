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
ll n,x,ans;
ll p[N];

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n)cin>>p[i];
  sort(p,p+n);
  x=p[n/2];
  rep(i,0,n)ans+=abs(p[i]-x);
  cout<<ans<<endl;
  return 0;
}
