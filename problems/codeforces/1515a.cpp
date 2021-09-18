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
  int n,x;
  cin>>n>>x;
  vi w(n);
  rep(i,0,n-1)cin>>w[i];
  int acc=0;
  rep(i,0,n-1){
    acc+=w[i];
    if(acc==x){
      if(i!=n-1){
        swap(w[i],w[i+1]);
      }else{
        cout<<"NO"<<endl;
        return;
      }
    }
  }
  cout<<"YES"<<endl;
  rep(i,0,n-1){
    cout<<w[i]<<" ";
  }
  cout<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

