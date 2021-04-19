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
using vi=vector<int>;

const int nmax=1e4;
const int amax=1e5+1;
int n,acc,maxacc,ans;
int a[nmax];

int main(){
  fastio;
  cin>>n;
  rep(i,0,n)cin>>a[i];
  rep(i,1,amax){
    maxacc=0;
    acc=0;
    rep(j,0,n){
      acc=i<=a[j]?acc+1:0;
      maxacc=max(maxacc,acc);
    }
    ans=max(ans,i*maxacc);
  }
  cout<<ans<<endl;
  return 0;
}

