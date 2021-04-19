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
using pii=pair<int,int>;

int t;

void solve(){
  int n;
  cin>>n;
  vi p(n),pos(n+1);
  rep(i,0,n-1){
    cin>>p[i];
    pos[p[i]]=i;
  }

  string s(n,'0');
  s[0]=s[n-1]='1';
  pii part={pos[1],pos[1]};
  rep(i,2,n-1){
    int idx=pos[i];
    part={min({part.fi,part.se,idx}),max({part.fi,part.se,idx})};
    if((part.se-part.fi+1)==i){
      s[i-1]='1';
    }
  }
  cout<<s<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

