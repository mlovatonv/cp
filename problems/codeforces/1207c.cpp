#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
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
  int n;
  ll a,b;
  string s;
  cin>>n>>a>>b>>s;
  ll ans=0;
  int i=0;
  while(i<n){ // initial zeros
    if(i<n-1&&s[i+1]=='1'){
      ans+=2LL*a+b;
      ++i;
      break;
    }
    ans+=a+b;
    ++i;
  }
  while(i<n){ // zeros between 1s
    if(s[i]=='0'){
      int j=i;
      while(j<n){ // count zeros
        if(s[j]=='1')break;
        ++j;
      }
      ll cnt=j-i;
      if(j==n){ // final zeros
        ans+=2LL*a+2LL*b;
        ans+=(cnt-1LL)*(a+b);
        break;
      }elif(cnt>1){
        ll zigzag=4LL*a+3LL*b+(cnt-2LL)*(a+b);
        ll ignore=cnt*(a+2LL*b);
        ans+=min(zigzag,ignore);
        i=j;
        continue;
      }
    }
    ans+=a+2LL*b;
    ++i;
  }
  ans+=b;
  cout<<ans<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

