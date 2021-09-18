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
using vi=vector<int>;

void solve(){
  int n,k;
  cin>>n>>k;
  vll a(n);
  rep(i,0,n-1)cin>>a[i];
  dbg(a);
  ll acc=0;
  int cnt=0;
  vi divs;
  rep(i,0,n-1){
    acc+=a[i];
    if(acc%2){
      ++cnt;
      acc=0;
      divs.pb(i+1);
    }
  }
  dbg(k);
  dbg(cnt);
  if(k<=cnt&&(cnt-k)%2==0){
    cout<<"YES"<<endl;
    rep(i,0,k-2)cout<<divs[i]<<' ';
    cout<<n<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

