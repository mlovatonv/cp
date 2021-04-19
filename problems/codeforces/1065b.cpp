#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(long long i=s;i<e;++i)
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

void solve(){
  ll n,m;
  cin>>n>>m;
  if(m==0){
    cout<<n<<' '<<n<<endl;
    return;
  }elif(m==1){
    cout<<max(n-2LL,0LL)<<' '<<max(n-2LL,0LL)<<endl;
    return;
  }
  ll mn=1e9,mx=1e9;
  mn=max(n-2LL*m,0LL);
  ll acc=0LL;
  rep(i,1,n+1){
    acc=(i*(i-1LL))/2LL;
    if(m<=acc){
      mx=n-i;
      break;
    }
  }
  mx=min(mx,n);
  cout<<mn<<' '<<mx<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

