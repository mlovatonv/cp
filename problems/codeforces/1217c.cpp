#include <iostream>
#include <vector>
#include "../dbg.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=(int)e;++i)
#define rrep(i,s,e) for(int i=s;i>=(int)e;--i)
#define ret(i,c) for(auto &i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using ll=long long;
using vi=vector<int>;


void solve(){
  string s;
  cin>>s;
  int n=s.size();

  vector<int> pre(n);
  rep(i,0,n-1){
    if(s[i]=='1')pre[i]=i;
    else pre[i]=i==0?-1:pre[i-1];
  }
  
  int x,ans=0;
  rep(r,0,n-1){
    x=0;
    rrep(l,r,max(0,r-17)){
      if(s[l]=='0')continue;
      x+=1<<(r-l);
      if(x<=r-(l==0?-1:pre[l-1])){
        ++ans;
      }
    }
  }

  cout<<ans<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)
  solve();
  return 0;
}

