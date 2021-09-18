#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rep2(i,s,e) for(int i=s;i<=e;i+=2)
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

int ceil(int a,int b){
  return (a+b-1)/b;
}

void solve(){
  int n;
  cin>>n;
  vi a(n);
  rep(i,0,n-1)cin>>a[i];

  vi p1{0},p2{0};
  rep2(i,0,n-1)p1.pb(p1.back()+a[i]); //odd
  rep2(i,1,n-1)p2.pb(p2.back()+a[i]); //even
  dbg(p1);
  dbg(p2);

  int ans=0,ei,oi,e1,e2,o1,o2;
  rep(i,0,n-1){
    oi=ceil(i,2);
    dbg(oi);
    o1=p1[oi];
    ei=i/2;
    dbg(ei);
    e1=p2[ei]; 

    o2=p2.back()-p2[ei+(i%2)];
    e2=p1.back()-p1[oi+(i%2==0)];

    if((e1+e2)==(o1+o2))++ans;
  }

  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

