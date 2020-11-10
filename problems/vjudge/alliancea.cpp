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
const int nmax=2e5;

bool vis[nmax];
int n,a;

int main(void){
  fastio;
  cin>>n;
  rep(i,1,n-1){
    cin>>a;
    vis[a]=true;
  }
  rep(i,1,n){
    if(!vis[i]){
      cout<<i<<endl;
      break;
    }
  }
  return 0;
}
