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

int t,a,b,k;

void solve(){
  cin>>a>>b>>k;
  ll ans=0;
  vi adj[a+b+1];
  vi vec(2*k);
  rep(i,0,k)cin>>vec[i];
  rep(i,0,k)cin>>vec[i+k],vec[i+k]+=a;
  rep(i,0,k){
    adj[vec[i]].pb(vec[i+k]);
    adj[vec[i+k]].pb(vec[i]);
  }
  rep(i,1,a+1){
    ret(j,adj[i]){
      ans+=k-len(adj[i])-len(adj[j])+1;
    }
  }
  ans/=2;
  cout<<ans<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

