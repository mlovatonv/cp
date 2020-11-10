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

int n,m,c,t,acc,v;
set<pi> s;

int main(void){
  fastio;
  cin>>n>>m;
  rep(i,1,n){
    cin>>c>>t;
    acc+=c*t;
    s.insert(mp(acc,i));
  }
  rep(i,1,m){
    cin>>v;
    auto it=s.lower_bound(mp(v,0));
    cout<<it->se<<endl;
  }
  return 0;
}
