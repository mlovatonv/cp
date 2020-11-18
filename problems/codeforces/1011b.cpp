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
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
const int nmax=102;

int n,m,ans;
int cnt[nmax];

int main(){
  fastio;
  cin>>n>>m;
  rep(i,0,m){
    int a;
    cin>>a;
    ++cnt[a];
  }
  rep(i,1,101){
    int acc=0;
    rep(j,0,101){
      acc+=cnt[j]/i;
    }
    if(acc>=n){
      ans=max(ans,i); 
    }
  }
  cout<<ans<<endl;
  return 0;
}
