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

int t;

void solve(){
  int n;
  cin>>n;
  int mid=n/2-1;
  vi p(n);
  rep(i,0,n-1)cin>>p[i];
  if(n<5){
    cout<<"0 0 0"<<endl;
    return;
  }
  dbg(mid);
  int gold=1;
  rep(i,1,n-1){
    if(p[i]==p[0])++gold;
    else break;
  }
  dbg(gold);
  int silver=1;
  rep(i,gold+1,n-1){
    if(p[i]!=p[i-1]&&silver>gold)break;
    ++silver;
  }
  dbg(silver);
  int bronze=0;
  rep(i,gold+silver,n-1){
    if(i>=mid+1){
      rrep(j,mid,0){
        if(p[j]!=p[i])break;
        --bronze;
      }
      break;
    }
    ++bronze;
  }
  dbg(bronze);
  if(bronze<gold){
    cout<<"0 0 0"<<endl;
    return; 
  }
  cout<<gold<<' '<<silver<<' '<<bronze<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

