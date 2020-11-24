#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const ll mod=1e9+7;
const int nmax=3e5+5;

vi adj[nmax];
int fx;

void dfs(int x,int p,int cnt,int& maxcnt){
  ++cnt;
  for(auto i:adj[x]){
    if(i!=p){
      if(cnt>=maxcnt){
        maxcnt=cnt;
        fx=i;
      }
      dfs(i,x,cnt,maxcnt);
    }
  }
}

int diam(){
  int maxcnt=1;
  dfs(1,0,1,maxcnt);
  dfs(fx,0,1,maxcnt);
  return maxcnt;
}

int main(){
  fastio;
  int n;
  cin>>n;
  rep(i,0,n-1){
    int a,b;
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  cout<<(diam()-1)*3<<endl;
  return 0;
}
