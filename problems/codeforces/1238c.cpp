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
  int h,n;
  cin>>h>>n;
  vi p(n);
  rep(i,0,n-1)cin>>p[i];
  int i=0,j=0,magic=0,cnt;
  while(i<n){
    j=i+1;
    while(j<n&&p[j-1]==p[j]+1){ // 8 7 ok 8 6 not ok
      ++j;
    }
    cnt=j-i;
    if((cnt+(i==0))%2&&p[j-1]>1){
      ++magic;
    }
    i+=cnt;
  }
  cout<<magic<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

