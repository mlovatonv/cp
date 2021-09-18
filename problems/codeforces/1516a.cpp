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
  int n,k;
  cin>>n>>k;
  int ik=k;
  vi a(n);
  rep(i,0,n-1)cin>>a[i];
  int i=0;
  while(k>0&&i<n-1){
    if(a[i]>k){
      a[i]=a[i]-k;
      k=0;
    }else{
      k=k-a[i];
      a[i]=0;
    }
    ++i;
  }
  a[n-1]+=(ik-k);
  rep(i,0,n-1)cout<<a[i]<<" ";
  cout<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

