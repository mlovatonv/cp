#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=2e5;

int n,x;
set<int> dp;

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n){
    cin>>x;
    auto it=dp.lower_bound(x);
    if(it!=dp.end()){
      dp.erase(it);
    }
    dp.insert(x);
  }
  cout<<dp.size()<<endl;
  return 0;
}

