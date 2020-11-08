#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=2e5;

ll a,b,x,s,ans;

int main(void){
  fastio;
  cin>>a>>b;
  if(a==b){
    cout<<"infinity"<<endl;
    return 0;
  }elif(a<b){
    cout<<0<<endl;
    return 0;
  }
  x=a-b;
  s=sqrt(x)+1;
  rep(i,1,s){
    if(x%i==0){
      if(b<i)++ans;
      if(b<(x/i)&&i!=(x/i))++ans;
    }
  }
  cout<<ans<<endl;
  return 0;
}
