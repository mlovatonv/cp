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
int n,a,b,c,ans;
set<pi> s;

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n){
    cin>>a>>b;
    s.insert({b,a});
  }
  int prev=0;
  for(auto i:s){
    if(i.se<prev)continue;
    else{++ans;prev=i.fi;}
  }
  cout<<ans<<endl;
  return 0;
}
