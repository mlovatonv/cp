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
  int zeros=count_if(all(s),[](const char c){return c=='0';});
  int ones=len(s)-zeros;
  if(ones){
    s="1";
    s.append(zeros,'0');
  }
  cout<<s<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

