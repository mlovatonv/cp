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

const int EMPTY=-2;
int t,n,a,lastOne=EMPTY,lastZero=EMPTY,ans;

void solve(){
  ans=0;
  lastOne=lastZero=EMPTY;
  cin>>n;
  rep(i,0,n){
    cin>>a;
    if(a){ // a is 1
      if(lastOne!=EMPTY&&lastZero!=EMPTY&&lastOne!=i-1){
        ans+=(lastZero-lastOne); 
      }
      lastOne=i;
    }else{ // a is 0
      lastZero=i; 
    }
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

