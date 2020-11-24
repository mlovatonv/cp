#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const ll mod=1e9+7;
const int nmax=2e5;

int n,k,m,q,t;
int cnt;

int main(){
  fastio;
  cin>>n>>m>>k;
  int acc;
  rep(i,0,n){
    acc=0;
    rep(j,0,k){
      cin>>t;
      acc+=t;
    }
    cin>>q;
    if(acc>=m&&q<=10)++cnt;
  }
  cout<<cnt<<endl;
  return 0;
}
