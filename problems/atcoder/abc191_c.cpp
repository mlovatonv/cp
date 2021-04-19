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

int h,w,ans;

void solve(){
  cin>>h>>w;
  vector<string> ss(h);
  rep(i,0,h)cin>>ss[i];
  rep(i,0,h){
    rep(j,0,w){
      if(ss[i][j]=='#'){
        //..
        //.X
        ans+=ss[i][j-1]=='.'&&ss[i-1][j]=='.'&&ss[i-1][j-1]=='.';
        //..
        //X.
        ans+=ss[i][j+1]=='.'&&ss[i-1][j]=='.'&&ss[i-1][j+1]=='.';
        //.X
        //..
        ans+=ss[i][j-1]=='.'&&ss[i+1][j]=='.'&&ss[i+1][j-1]=='.';
        //X.
        //..
        ans+=ss[i][j+1]=='.'&&ss[i+1][j]=='.'&&ss[i+1][j+1]=='.';
        //.#
        //#X
        ans+=ss[i][j-1]=='#'&&ss[i-1][j]=='#'&&ss[i-1][j-1]=='.';
        //#.
        //X#
        ans+=ss[i][j+1]=='#'&&ss[i-1][j]=='#'&&ss[i-1][j+1]=='.';
        //#X
        //.#
        ans+=ss[i][j-1]=='#'&&ss[i+1][j]=='#'&&ss[i+1][j-1]=='.';
        //X#
        //#.
        ans+=ss[i][j+1]=='#'&&ss[i+1][j]=='#'&&ss[i+1][j+1]=='.';
      }
    }
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

