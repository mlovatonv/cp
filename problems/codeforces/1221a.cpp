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
  vi a(n);
  rep(i,0,n-1)cin>>a[i];
  sort(all(a));
  int i=0,j,cnt;
  while(i<n&&a[i]<2048){
    j=i+1;
    while(j<n&&a[i]==a[j]){
      ++j;
    }
    cnt=j-i;
    rep(k,1,cnt/2){
      a[j-k]=a[i]+a[j-k];
    }
    i=j-(cnt/2);
  }
  if(i<n&&a[i]==2048){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

