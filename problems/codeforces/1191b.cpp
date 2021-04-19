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

int suti(const char a){
  if(a=='m')return 0;
  if(a=='p')return 1;
  if(a=='s')return 2; 
  return 0;
}

void solve(){
  string s;
  int m[9][3];
  rep(i,0,9)rep(j,0,3)m[i][j]=0;
  rep(i,0,3){
    cin>>s; 
    m[s[0]-'1'][suti(s[1])]+=1;
  }
  int ans=24;
  rep(i,0,9){
    rep(j,0,3){
      if(i<7){
        int t=3-(m[i][j]>0)-(m[i+1][j]>0)-(m[i+2][j]>0);
        ans=min(ans,t);
      }
      ans=min(ans,3-m[i][j]);
    }
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

