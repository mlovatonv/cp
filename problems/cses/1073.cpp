#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

int n,k;
set<pi> s;

int main(void){
  fastio;
  cin>>n;
  cin>>k;
  s.insert({k,0});
  rep(i,1,n){
    cin>>k;
    auto x=s.upper_bound(mp(k,i));
    if(x!=s.end())s.erase(x);
    s.insert(mp(k,i));
  }
  cout<<s.size()<<endl;
  return 0;
}
