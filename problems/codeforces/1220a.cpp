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
#define ret(i,c) for(auto &i:c)
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
  map<char,int> m;
  m['o']=m['n']=m['e']=m['z']=m['r']=0;
  ret(c,s){
    ++m[c];
  }
  int n1=min({m['o'],m['n'],m['e']});
  m['o']-=n1;
  m['n']-=n1;
  m['e']-=n1;
  int n2=min({m['z'],m['e'],m['r'],m['o']});
  rep(i,1,n1)cout<<"1 ";
  rep(i,1,n2)cout<<"0 ";
}

int main(){
  fastio;
  solve();
  return 0;
}

