#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
#define ret(i,c) for(auto &i:c)
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
  int n;
  cin>>n;
  vector<vector<ll>> m(n,vector<ll>(n));
  rep(i,0,n-1){
    rep(j,0,n-1){
      cin>>m[i][j];
    }
  }

  vector<ll> ans;
  ll temp;

  temp=sqrt((m[1][0]*m[2][0])/m[2][1]);
  ans.pb(temp);
  temp=sqrt((m[1][0]*m[2][1])/m[2][0]);
  ans.pb(temp);

  rep(i,2,n-1){
    temp=sqrt((m[i][0]*m[i][1])/m[1][0]);
    ans.pb(temp);
  }

  ret(i,ans){
    cout<<i<<endl;
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

