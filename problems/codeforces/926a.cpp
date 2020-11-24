#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define in insert
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef set<ll> si;
const ll mod=1e9+7;
const int nmax=2e5;

si s;

void build(){
  s.in(1);
  vi pot2,pot3;
  ll a=1;
  rep(i,0,30){
    a*=2LL;
    pot2.pb(a);
    s.in(a);
  }
  a=1;
  rep(i,0,19){
    a*=3LL;
    pot3.pb(a);
    s.in(a);
  }
  rep(i,0,30)rep(j,0,19)s.in(pot2[i]*pot3[j]);
}

int main(){
  fastio;
  build();
  ll l,r;
  cin>>l>>r;
  auto i=s.lower_bound(l);
  auto j=s.upper_bound(r);
  int ans=distance(i,j);
  cout<<ans<<endl;
  return 0;
}
