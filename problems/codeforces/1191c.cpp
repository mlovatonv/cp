#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
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
  ll n,k;
  int m;
  const int mmax=1e5+10;
  ll p[mmax];
  ll elim=0;
  ll prevpage=-1;
  ll pagesize=0;
  ll page=-1;
  ll pos=-1;
  ll ans=0;

  cin>>n>>m>>k;
  rep(i,0,m)cin>>p[i];
  rep(i,0,m){
    pos=p[i]-elim-1LL;
    page=pos/k;
    //cout<<"p[i]="<<p[i]<<" page="<<page<<endl;
    if(prevpage==-1){
      prevpage=page;
      ++pagesize;
    }else{
      if(prevpage==page){
        ++pagesize;
      }else{
        elim+=pagesize;
        pagesize=0;
        prevpage=-1;
        ++ans;
        --i;
        //cout<<"ans="<<ans<<" elim="<<elim<<endl;
      }
    }
  }
  ++ans; // last page
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

