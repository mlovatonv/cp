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
  int n,m;
  cin>>n>>m;
  vector<vi> vv(n,vi(m));
  rep(i,0,n-1){
    rep(j,0,m-1){
      cin>>vv[i][j];
    }
    sort(all(vv[i]));
  }

  vector<vi> ans(n,vi(m));
  pair<int,int> min_col_val;
  rep(r,0,m-1){
    // get min
    min_col_val={-1,1e9+10};
    rep(i,0,n-1){
      int min_val=*vv[i].begin();
      if(min_val<min_col_val.se){
        min_col_val={i,min_val};
      }
    }
    // get max
    rep(i,0,n-1){
      if(i==min_col_val.fi){
        ans[i][r]=min_col_val.se;
        vv[i].erase(vv[i].begin());
      }else{
        int max_val=*vv[i].rbegin();
        ans[i][r]=max_val;
        vv[i].erase(--vv[i].end());
      }
    }   
  }

  ret(i,ans){
    ret(j,i){
      cout<<j<<' ';
    }
    cout<<endl;
  }
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

