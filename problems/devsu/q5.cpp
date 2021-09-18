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
  string input;
  cin>>input;
  int n=count(all(input),'[')-1;
  vector<vector<int>> m(n,vector<int>(n)),dp(n,vector<int>(n));

  rep(i,0,(int)len(input)-1){
    char c=input[i];
    if(c=='['||c==','||c==']'){
      input[i]=' ';
    }
  }
  stringstream ss(input);
  int cnt=-1;
  int temp;
  while(ss>>temp){
    ++cnt;
    int i=cnt/n,j=cnt-i*n;
    m[i][j]=temp;
  }

  dp[0][n-1]=m[0][n-1];
  rrep(i,n-2,0){
    dp[0][i]=dp[0][i+1]+m[0][i];
  }
  rep(i,1,n-1){
    dp[i][n-1]=dp[i-1][n-1]+m[i][n-1];
  }
  
  rep(i,1,n-1){
    rrep(j,n-2,0){
      dp[i][j]=max(dp[i-1][j],dp[i][j+1])+m[i][j];
    }
  }

  dbg(m);
  dbg(dp);
  cout<<dp[n-1][0]<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

