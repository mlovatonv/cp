#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=2e5;

int n,h,a,ans;

int main(void){
  fastio;
  cin>>n>>h;
  rep(i,0,n){
    cin>>a;
    ans+=a>h?2:1; 
  }
  cout<<ans<<endl;
  return 0;
}
