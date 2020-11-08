#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=1002;

int n,m,cnt;
char g[nmax][nmax];
bool vis[nmax][nmax];

void search(int i, int j){
  if(vis[i][j])return;
  vis[i][j]=true;
  if(g[i-1][j]=='.')search(i-1,j);
  if(g[i+1][j]=='.')search(i+1,j);
  if(g[i][j-1]=='.')search(i,j-1);
  if(g[i][j+1]=='.')search(i,j+1);
}

int main(void){
  fastio;
  cin>>n>>m;
  rep(i,1,n){
    rep(j,1,m){
      cin>>g[i][j];
    }
  }
  rep(i,1,n){
    rep(j,1,m){
      if(g[i][j]=='.'&&!vis[i][j]){
        search(i,j);
        ++cnt;
      }
    }
  }
  cout<<cnt<<endl;
  return 0;
}
