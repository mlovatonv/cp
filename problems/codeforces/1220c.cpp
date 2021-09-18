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
  string s;
  cin>>s;
  int n=len(s);

  vector<char> v; // vector of min char

  v.pb(s[0]);
  rep(i,1,n-1){
    if(v.back()<=s[i]){
      v.pb(v.back());
    }else{
      v.pb(s[i]);
    }
  }
  
  rep(i,0,n-1){
    if(s[i]==v[i]){
      cout<<"Mike"<<endl;
    }else{
      cout<<"Ann"<<endl;
    }
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

