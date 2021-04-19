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
using vi=vector<int>;

int t;
int n,x,y,d;
int ans;
const int inf=1e9+1;

int ceil(int x,int y){
  return 1+((x-1)/y);
}

void solve(){
  cin>>n>>x>>y>>d;
  ans=inf;
  if(x%d==y%d){ // direct case
    ans=min(ans,abs(y/d-x/d));
  }
  if(1%d==y%d){ // to 1
    ans=min(ans,ceil(x,d)+y/d);
  }
  if(n%d==y%d){ // to n
    ans=min(ans,ceil(n-x,d)+(n-y)/d);
  }
  if(ans==inf){ // invalid
    ans=-1;
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

