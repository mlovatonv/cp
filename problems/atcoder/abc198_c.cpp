#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ll=long long;
using vi=vector<int>;

void solve(){
  double r,x,y,d;
  int ans;
  cin>>r>>x>>y;
  d=sqrt(pow(x,2.0)+pow(y,2.0));
  if(d<r){
    ans=2;
  }else{
    ans=(int)floor(floor(d/r)+(ceil(d/r)!=floor(d/r)?1.0:0.0));
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

