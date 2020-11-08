#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=998244353;

ll a,b,c,ans;

ll getsum(ll x){
  ll s=(x*(x+1))/2;
  return s%mod;
}

int main(void){
  fastio;
  cin>>a>>b>>c;
  ans=(getsum(a)*getsum(b))%mod;
  ans=(ans*getsum(c))%mod;
  cout<<ans<<endl;
  return 0;
}
