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

ll n,ans;

void solve(){
  cin>>n;
  if(n<=1){
    cout<<0<<endl;
    return;
  };
  cout<<n-1<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

