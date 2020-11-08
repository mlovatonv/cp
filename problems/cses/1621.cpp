#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;++i)
#define fi first
#define se second
using namespace std;

ll n,x;
set<ll> s;

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n){
    cin>>x;
    s.insert(x);
  }
  cout<<s.size()<<endl;
  return 0;
}
