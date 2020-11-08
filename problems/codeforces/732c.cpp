#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<ll,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
using namespace std;

const int N=3;
ll ans,mx;
array<ll,N> meals;

int main(void){
  fastio;
  rep(i,0,N){
    cin>>meals[i];
    mx=max(mx,meals[i]);
  }
  rep(i,0,N)if(meals[i]<mx)ans+=(mx-1)-meals[i];
  cout<<ans<<endl;
  return 0;
}
