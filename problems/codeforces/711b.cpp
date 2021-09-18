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
using vi=vector<ll>;
using vvi=vector<vi>;


void solve(){
  int n;
  cin>>n;
  vvi mat(n,vi(n));
  pair<int,int> zero_pos;
  rep(i,0,n-1){
    rep(j,0,n-1){
      cin>>mat[i][j];
      if(mat[i][j]==0){
        zero_pos={i,j};
      }
    }
  }

  if(n==1){
    cout<<1<<endl;
    return;
  }

  // calculate zero
  int col=zero_pos.se==0?1:0;
  ll s1=0,s2=0;
  rep(i,0,n-1){
    s1+=mat[i][col];
    s2+=mat[i][zero_pos.se];
  }
  if(s2>=s1){
    cout<<-1<<endl;
    return; 
  }
  mat[zero_pos.fi][zero_pos.se]=s1-s2;


  // check sums
  ll acc=0;
  rep(i,0,n-1){
    acc=0;
    rep(j,0,n-1)acc+=mat[i][j];
    if(acc!=s1){
      cout<<-1<<endl;
      return;    
    }
    acc=0;
    rep(j,0,n-1)acc+=mat[j][i];
    if(acc!=s1){
      cout<<-1<<endl;
      return;    
    }
  }
  acc=0;
  rep(i,0,n-1)acc+=mat[i][i];
  if(acc!=s1){
    cout<<-1<<endl;
    return;    
  }
  acc=0;
  rep(i,0,n-1)acc+=mat[i][n-i-1];
  if(acc!=s1){
    cout<<-1<<endl;
    return;    
  }

  // ans
  cout<<mat[zero_pos.fi][zero_pos.se]<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

