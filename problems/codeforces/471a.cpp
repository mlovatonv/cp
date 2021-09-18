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
  int n=6;
  map<int,int> m;
  rep(i,0,n-1){
    int l;
    cin>>l;
    ++m[l];
  }

  bool valid=false;
  ret(i,m){
    if(i.se>=4){
      m[i.fi]-=4;
      valid=true;
    }
  }

  if(!valid){
    cout<<"Alien"<<endl;
    return;
  }

  vector<int> comp;
  ret(i,m){
    rep(j,1,i.se) {
      comp.pb(i.fi);  
    }
  }

  if(comp[0]==comp[1]){
    cout<<"Elephant"<<endl;
  }else{
    cout<<"Bear"<<endl;
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

