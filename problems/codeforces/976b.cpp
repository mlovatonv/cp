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

ll ceil(ll x,ll y){
  return 1LL+((x-1LL)/y);
}

void solve(){
  ll n,m,k;
  cin>>n>>m>>k;
  if(k<n){
    cout<<k+1LL<<" 1"<<endl;
  }else{
    ll z=n*m-k;
    ll w=ceil(z,m-1LL);
    ll v=z-(w-1LL)*(m-1LL);
    ll a=w%2LL?v:(m-1LL)-(v-1LL);
    dbg(z);
    dbg(w);
    dbg(v);
    dbg(a);
    cout<<w<<" "<<a+1LL<<endl;
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

