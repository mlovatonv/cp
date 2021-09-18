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
  int k;
  cin>>k;
  if(k>36){
    cout<<"-1"<<endl;
    return;
  }
  while(k>=2){
    cout<<"8";
    k-=2;
  }
  if(k==1){
    cout<<"4";
  }
  cout<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

