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

int n,k,a,b,ans;
set<pi> movies,members;

int main(void){
  fastio;
  cin>>n>>k;
  rep(i,0,n){
    cin>>a>>b;
    //se=>entrada fi=>salida
    movies.emplace(b,a);
  }
  rep(i,1,k+1)members.emplace(0,i);
  for(auto i:movies){
    auto it=members.upper_bound(mp(i.se,INT_MAX));
    if(it==members.begin())continue;
    ++ans;
    members.emplace(i.fi,(--it)->se);
    members.erase(it);
  }
  cout<<ans<<endl;
  return 0;
}
