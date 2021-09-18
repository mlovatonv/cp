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
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ll=long long;
using vi=vector<int>;


void solve(){
  int n;
  cin>>n;
  vi a(n),st;
  rep(i,0,n-1)cin>>a[i];
  
  st.push_back(a[0]);
  cout<<st.back()<<endl;

  rep(i,1,n-1){
    if(a[i]==1){
      st.push_back(a[i]);
    }else{
      while((st.back()+1)!=a[i]){
        st.pop_back();
      }
      st.back()=a[i];
    }
    int y=len(st)-2;
    rep(j,0,y)cout<<st[j]<<".";
    cout<<st.back()<<endl;
  }
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)
  solve();
  return 0;
}

