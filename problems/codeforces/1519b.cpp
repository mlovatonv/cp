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

const int nmax=110;
vector<vector<ll>> mm(nmax,vector<ll>(nmax));

void compute(){
  rep(i,1,100){
    rep(j,2,100){
      mm[i][j]=mm[i][j-1]+i;
    }
    mm[i+1][1]=mm[i][1]+1;
  }
}

void solve(){
  int n,m,k;
  cin>>n>>m>>k;
  if(mm[n][m]==k){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}

int main(){
  fastio;
  compute();
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

