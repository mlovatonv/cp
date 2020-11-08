#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

const int N=2e5;
int n,a,b,idx;
array<int,3> abi[N];
int ans[N];
set<pi> s;

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n){
    cin>>abi[i][0]>>abi[i][1];
    abi[i][2]=i;
  }
  sort(abi,abi+n);
  s.insert({0,1});
  rep(i,0,n){
    a=abi[i][0];
    b=abi[i][1];
    idx=abi[i][2];
    auto it=s.lower_bound(mp(a,0));
    if(it==s.begin())ans[idx]=s.size()+1;
    else{
      ans[idx]=(--it)->se;
      s.erase(it);
    }
    s.insert(mp(b,ans[idx]));
  }
  cout<<s.size()<<endl;
  rep(i,0,n)cout<<ans[i]<<' ';
  cout<<endl;
  return 0;
}
