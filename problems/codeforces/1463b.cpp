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
using vll=vector<ll>;


void solve(){
  int n;
  cin>>n;
  vll a(n);
  ll odd=0,even=0;
  rep(i,0,n-1){
    cin>>a[i];
    if(i%2)odd+=a[i];
    else even+=a[i];
  }
  int p=odd>even;
  rep(i,0,n-1){
    if(i%2==p)cout<<a[i]<<" ";
    else cout<<"1 ";
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

