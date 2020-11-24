#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int nmax=2e5;

int t;
ll k,x;

pii find(int n){
  int aux=n;
  rrep(i,sqrt(aux),2){
    if(aux%i==0){
      while(aux%i==0)aux/=i;
      if(aux>1)return mp(i,aux);
    }
  }
  return mp(1,n);
}

void solve(){
  cin>>k>>x;
  pii cp=find(x);
  //cout<<"cp="<<cp.fi<<" "<<cp.se<<endl;
  ll ans=cp.fi+cp.se;
  rep(i,1,k-2)ans+=1;
  cout<<ans<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

