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
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=4e5;

int n,k;
ll ans;
ll f[nmax];

int main(void){
  fastio;
  cin>>n>>k;
  rep(i,2,2*n){
    f[i]=min(i-1,2*n+1-i);
  }
  rep(i,2,2*n){
    if(i-k>=0){
      ans+=f[i]*f[i-k];
    }
  }
  cout<<ans<<endl;
  return 0;
}
