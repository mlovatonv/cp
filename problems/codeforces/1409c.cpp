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
  int n,x,y,
      ans_s,ans_e=1e9,ans_i,
      n2,
      s,e,_i;
  cin>>n>>x>>y;

  rep(i,1,50){
    if((y-x)%i==0){
      n2=(y-x)/i+1;
      if(n2==n){ // x ... y
        s=x;
        e=y;
        _i=i;
      }elif(n2<n){
        s=x-(n-n2)*i;
        if(s>0){ // s ... x ... y
          e=y;
          _i=i;
        }else{ // s ... x ... y ... e
          s=x-i*(x/i);
          e=y+(n-n2-(x/i))*i;
          _i=i;
        }
      }else{
        continue;
      }
      if(0<s&&e<ans_e&&y<=e){
        ans_e=e;
        ans_i=_i;
        ans_s=s;
      }
    }
  }

  for(int i=ans_s;i<=ans_e;i+=ans_i){
    cout<<i<<" ";
  }
  cout<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)
  solve();
  return 0;
}

