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

const int amax=1e4+1;
bool is_ps[amax]; // is perfect square?

void fill_is_ps(){
  rep(i,1,100){
    is_ps[i*i]=true; 
  }
}

void solve(){
  int n;
  cin>>n;
  vi a(n);
  rep(i,0,n-1)cin>>a[i];
  rep(i,0,n-1){
    if(!is_ps[a[i]]){
      cout<<"YES"<<endl;
      return;
    }
  }
  cout<<"NO"<<endl;
}

int main(){
  fastio;
  fill_is_ps();
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

