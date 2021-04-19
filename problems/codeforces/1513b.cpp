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
using vi=vector<ll>;

const ll mod=1e9+7;

ll perm(ll a,ll b){
  ll ans=1;
  //cout<<"a="<<a<<" b="<<b<<endl;
  b=a-b+1;
  //cout<<"a2="<<a<<" b2="<<b<<endl;
  rep(i,b,a+1){
    ans=((ans%mod)*(i%mod))%mod;
  }
  ans%=mod;
  return ans;
}

void solve(){
  int n;
  cin>>n;
  vi a(n);
  rep(i,0,n)cin>>a[i];
  ll s=0b111111111111111111111111111111; // minimum 1
  rep(i,0,n){
    s&=a[i];
  }
  int c=0; // count numbers
  rep(i,0,n)if(a[i]==s)++c; 
  if(c<2){
    cout<<0<<endl;
    return;
  }
  //cout<<"c="<<c<<endl;
  ll ans=(perm(c,2)*perm(n-2,n-2))%mod;
  cout<<ans<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

