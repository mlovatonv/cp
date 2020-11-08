#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<ll,int>
#define mp make_pair
#define fi first
#define se second
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

int n,m,hi;
ll ti;
set<pi> h;

int main(void){
  fastio;
  cin>>n>>m;
  rep(i,0,n){
    cin>>hi;
    h.insert(mp(hi,i));
  }
  rep(i,0,m){
    cin>>ti;
    auto x=h.lower_bound(mp(ti+1,-1));
    if(x==h.begin())cout<<-1<<endl;
    else{
      cout<<(--x)->fi<<endl;
      h.erase(x);
    }
  }
  return 0;
}
