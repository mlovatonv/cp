#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
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

ll n,ans=-1,x,acc,v,p;

int main(){
  fastio;
  cin>>n>>x;
  x*=100;
  rep(i,1,n){
    cin>>v>>p;
    acc+=v*p;
    if(acc>x&&ans==-1)ans=i;
  }
  cout<<ans<<endl;
  return 0;
}

