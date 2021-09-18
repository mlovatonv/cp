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
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ll=long long;
using vll=vector<ll>;

ll ceil(ll x,ll y){
  return 1 + ((x - 1) / y);
}

void solve(){
  int n,k,z;
  cin>>n>>k>>z;
  vll a(n),pre(n+1);
  rep(i,0,n-1)cin>>a[i];
  rep(i,1,n)pre[i]+=pre[i-1]+a[i-1];

  ll ans=0,s;
  // a0 case
  int x=min(2*z,k+1),
      t=z==0?k:k-2*z+1,
      w=x==(k+1)?0:t;
  s=a[0]*ceil(x,2)+a[1]*(x/2LL)+(pre[1+w]-pre[1]);
  ans=max(ans,s);
  // cases after a0
  rep(i,1,n-2){
    int j=i+1,
        y=k-i-1, // remaining moves before i
        x=min(2*z,y), // moves used in the loop
        w=x==y?0:y-(ceil(x,2)+(x/2LL)); // remaining moves after i
    s=pre[i]+a[i]*ceil(x,2)+a[j]*(x/2LL)+(pre[j+w]-pre[j]);
    ans=max(ans,s);
    dbg(i);
    dbg(w);
    dbg(s);
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

