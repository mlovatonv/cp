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

int n,m,x;

void solve(){
  cin>>n;
  m=n/2+1;
  x=n%2?n/2+1:n/2;
  cout<<m<<endl; // minimum m
  rep(i,0,n/2)cout<<1<<" "<<i+1<<endl;
  rep(i,0,x)cout<<m<<" "<<i+1<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

