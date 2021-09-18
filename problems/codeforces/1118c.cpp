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
  int n;
  cin>>n;
  map<int,int> occ;
  rep(i,0,(n*n)-1){
    int a;
    cin>>a;
    ++occ[a];
  }
  dbg(occ);

  auto search_and_subs = [&](int v){
    ret(i, occ){
      if(i.se>=v){
        occ[i.fi]-=v;
        return i.fi;
      }
    }
    return 0;
  };
 
  vector<vi> ans(n,vi(n));

  //fill 4
  rep(i,0,n/2-1){
    rep(j,0,n/2-1){
      int k=search_and_subs(4);
      dbg(k);
      if(k==0){
        cout<<"NO"<<endl;
        return;
      }
      ans[i][j]=ans[i][n-1-j]=ans[n-1-i][j]=ans[n-1-i][n-1-j]=k;
    }
  }

  if(n%2){
    //fill 2
    int m=n/2;
    rep(i,0,n/2-1){
      int k=search_and_subs(2);
      dbg(k);
      if(k==0){
        cout<<"NO"<<endl;
        return;
      }
      ans[m][i]=ans[m][n-1-i]=k;
    }
    rep(i,0,n/2-1){
      int k=search_and_subs(2);
      if(k==0){
        cout<<"NO"<<endl;
        return;
      }
      ans[i][m]=ans[n-1-i][m]=k;
    }

    //fill 1
    int k=search_and_subs(1);
    dbg(k);
    if(k==0){
      cout<<"NO"<<endl;
      return;
    }
    ans[m][m]=k;
  }

  cout<<"YES"<<endl;
  rep(i,0,n-1){
    rep(j,0,n-1){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

