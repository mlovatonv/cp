#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;++i)
#define fi first
#define se second
using namespace std;

int t;
ll a,b,c,d;

int main(void){
  fastio;
  cin>>t;
  while(t--){
    cin>>a>>b>>c;
    d=(a+b+c)-1;
    cout<<d<<endl;
  }
  return 0;
}
