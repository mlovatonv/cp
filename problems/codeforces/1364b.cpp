#include <iostream>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
#define ret(i,c) for(auto &i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using ll=long long;
using vi=vector<int>;


void solve(){
  int n;
  cin>>n;
  vector<int> p(n);
  rep(i,0,n-1)cin>>p[i];

  vector<int> d(n);
  rep(i,0,n-2)d[i]=abs(p[i]-p[i+1]);

  vector<int> ans;
  int i=0,j,acc;
  while(i<n){
    ans.pb(p[i]);
    acc=0;
    j=i;
    do{
      acc+=d[j];
      ++j;
    }while(j<n-1&&abs(p[i]-p[j+1])==(acc+d[j]));
    //cout<<"acc="<<acc<<" j="<<j<<endl;
    i=j;
  }

  cout<<ans.size()<<endl;
  ret(x,ans)cout<<x<<" ";
  cout<<endl; 
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)
  solve();
  return 0;
}

