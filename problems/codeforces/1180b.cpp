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
using pii=pair<int,int>;

void set_greater_comb(int& first,int& second){ // first is greater or equal
   
}

void solve(){
  int n;
  cin>>n;
  vector<pair<int,int>> v;
  rep(i,0,n){
    int a;
    cin>>a;
    v.pb({a,i});
  }
  sort(all(v),greater<pii>());
  for(int i=0;i<=n-2;i+=2){
    set_greater_comb(v[i].fi,v[i+1].fi);
  }
  sort(all(v),[](pii i,pii j){ return i.se<j.se; });
  ret(i,v)cout<<i.fi<<' ';
  cout<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

