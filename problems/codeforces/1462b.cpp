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
  cin>>n;
  string s;
  cin>>s;
  string ss="2020";
  rep(i,0,4){
    string s1=s.substr(0,i),
           e1=s.substr(n-(4-i)),
           s2=ss.substr(0,i),
           e2=ss.substr(i);
    if(s1==s2&&e1==e2){
      cout<<"YES"<<endl;
      return;
    }
  }
  cout<<"NO"<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

