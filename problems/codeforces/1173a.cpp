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

int x,y,z,diff;

void solve(){
  cin>>x>>y>>z;
  diff=x-y;
  if(z!=0&&abs(diff)<=z)cout<<"?\n";
  elif(diff<0)cout<<"-\n";
  elif(diff>0)cout<<"+\n";
  elif(diff==0)cout<<"0\n";
}

int main(){
  fastio;
  solve();
  return 0;
}

