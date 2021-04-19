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
using vi=vector<int>;

int t;

int ans(int hr,int n){
  return hr%n?hr%n:n;
}

void solve(){
  ll n,k;
  cin>>n>>k;
  if(n%2){
    if(k<=n/2){
      cout<<ans(k,n)<<endl;
      return;
    }else{
      dbg(n);
      dbg(k);
      ll x=k-n/2LL; // x=k including llervals
      dbg(x);
      ll itvsize=n/2LL+1LL; // llerval size
      dbg(itvsize);
      ll bitv=(x-1LL)/(n/2LL); // number of llervals before x
      dbg(bitv);
      ll bk=bitv*(n/2LL); // number of k before x
      dbg(bk);
      ll bels=itvsize*bitv; // number of elements before x
      dbg(bels);
      ll aels=(x-bk)+1LL;
      dbg(aels);
      ll els=bels+aels; // elements in llervals before and after k
      dbg(els);
      cout<<ans(n/2LL+els,n)<<endl;
      return;
    }
  }else{
    cout<<ans(k,n)<<endl;
    return;
  }
}

int main(){
  fastio;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

