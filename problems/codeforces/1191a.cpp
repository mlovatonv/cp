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

char cat[4]={'D','A','C','B'};

void solve(){
  int x,a=0;
  char b='E',tb;
  cin>>x;
  rep(i,0,3){
    tb=cat[(x+i)%4];
    if(tb<b){
      a=i;
      b=tb;
    }
  }
  cout<<a<<' '<<b<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

