#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,s,e) for(ll i=s;i<e;++i)
#define fi first
#define se second
using namespace std;

ll n,w;

int main(void){
  fastio;
  cin>>n;
  rep(i,1,n+1){
    w=i*i*(i*i-1)/2;
    if(i>2)w-=4*(i-1)*(i-2);
    cout<<w<<endl;
  }
  return 0;
}
