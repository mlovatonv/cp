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

int t;

void solve(){
  int n;
  cin>>n;
  int maxties=n/2;
  dbg(maxties);
  rep(i,1,n-1){
    rep(j,i+1,n){
      dbg(j);
      dbg(i);
      if((j-i)<maxties){
        cout<<"1 ";  
      }elif((j-i)>maxties){
        cout<<"-1 ";  
      }else{
        cout<<n%2<<' ';
      }
    }
  }
  cout<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

