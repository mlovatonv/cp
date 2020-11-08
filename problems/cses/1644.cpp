#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<ll,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

const int N=2e5+1;
int n,a,b;
ll x,ans=LLONG_MIN;
ll p[N];
set<pi> s;

int main(void){
  fastio;
  cin>>n>>a>>b;
  rep(i,1,n+1){
    cin>>x;
    p[i]=p[i-1]+x;
    if(i>=a)s.insert({p[i-a],i-a});
    if(!s.empty())ans=max(ans,p[i]-s.begin()->fi);
    if(i>=b)s.erase({p[i-b],i-b});
  }
  cout<<ans<<endl;
  return 0;
}
