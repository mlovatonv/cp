#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

const int N=2e5;
int n;
ll a,d,t,ans;
pi ad[N];

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n)cin>>ad[i].fi>>ad[i].se;
  sort(ad,ad+n);
  rep(i,0,n){
    t+=ad[i].fi;
    ans+=ad[i].se-t;
  }
  cout<<ans<<endl;
  return 0;
}
