#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define itr(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int nmax=2e5+10;
int n,a[nmax],ans;
vi b;
bool divis;

int main(){
  fastio;
  cin>>n;
  rep(i,0,n)cin>>a[i];
  sort(a,a+n);
  if(n==1||a[0]!=a[1])ans=1;
  b.pb(a[0]);
  rep(i,1,n){
    divis=false;
    itr(j,b)
      if(a[i]%j==0){
        divis=true;
        break;
      }
    if(!divis){
      ++ans;
      b.pb(a[i]);
    }
  }
  cout<<ans<<endl;
  return 0;
}
