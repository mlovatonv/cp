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
using vll=vector<pair<ll,ll>>;

vll prime_fact(ll n){
  vll pf;
  ll count=0;
  while (!(n%2LL)){ // count the number of times 2 divides 
    n>>=1LL; // equivalent to n=n/2;
    count++;
  }
  if (count)pf.pb({2,count}); // if 2 divides it
  ll maxi=sqrtl(n);
  for (ll i=3;i<=maxi;i+=2) { // check for all the possible numbers
    count=0;
    while(n%i==0){
      count++;
      n/=i;
    }
    if (count)pf.pb({i,count});
  }
  if(n>2)pf.pb({n,1}); // if n at the end is a prime number.
  return pf;
}

void solve(){
  ll n,p;
  cin>>n>>p;
  vll pf=prime_fact(p);
  dbg(pf);
  ll ans=1;
  ret(i,pf){
    dbg(i);
    ll k=(i.se/n);
    if(k){
      ll t=1;
      rep(j,1,k)t*=i.fi;
      ans*=t;
    }
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

