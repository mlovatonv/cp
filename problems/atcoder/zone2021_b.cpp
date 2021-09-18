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
using vd=vector<double>;

void solve(){
  int n;
  double D,H;
  cin>>n>>D>>H;
  vd d(n),h(n);
  rep(i,0,n-1){
    cin>>d[i]>>h[i];
  }
  double l=0.0,r=1000.0,mid;
  auto check=[&](double b)->bool{
    double a=(H-b)/D;
    rep(i,0,n-1){
      if((d[i]*a+b)<h[i]){
        return false;
      }
    }
    return true;
  };
  while(fabs(l-r)>1e-5){
    mid=l+(r-l)/2.0f;
    dbg(mid);
    if(check(mid)){
      dbg("r=mid");
      r=mid;
    }else{
      dbg("l=mid");
      l=mid;
    }
  }
  cout.setf(ios::fixed);
  cout<<setprecision(15)<<mid<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

