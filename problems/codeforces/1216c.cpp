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
#define ret(i,c) for(auto &i:c)
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
  vi x(9),y(9);
  rep(i,1,6){
    cin>>x[i]>>y[i];
  }
  x[7]=x[1];
  y[7]=y[2];
  x[8]=x[2];
  y[8]=y[1];
  auto check1=[](vi v,int i){
    bool ans=(
        (v[i]<min(v[3],v[4])&&v[i]<min(v[5],v[6]))||
        (v[i]>max(v[3],v[4])&&v[i]>max(v[5],v[6]))||
        (v[i]>max(v[3],v[4])&&v[i]<min(v[5],v[6]))||
        (v[i]<min(v[3],v[4])&&v[i]>max(v[5],v[6])));
    dbg(ans);
    return ans;
  };
  auto check2=[](vi v,int i1,int i2){
    int l=max(v[i1],v[i1+1]),r=min(v[i2],v[i2+1]);
    bool ans=(
        v[1]<=l&&v[1]<=r&&
        l<=v[2]&&r<=v[2]&&
        (r-l)>0);
    dbg(ans);
    return ans;
  };
  auto check3=[&](int i){
   bool ii1=x[3]<=x[i]&&x[i]<=x[4]&&y[3]<=y[i]&&y[i]<=y[4];
   bool ii2=x[5]<=x[i]&&x[i]<=x[6]&&y[5]<=y[i]&&y[i]<=y[6];
   bool ans=!(ii1||ii2);
   dbg(ans);
   return ans;
  };
  bool ans=check1(x,1)||
           check1(x,2)||
           check1(y,1)||
           check1(y,2)||
           check2(x,3,5)||
           check2(y,3,5)||
           check2(x,5,3)||
           check2(y,5,3)||
           check3(1)||
           check3(2)||
           check3(7)||
           check3(8);
  if(ans)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

