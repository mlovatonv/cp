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

int t;

void solve(){
  int n;
  cin>>n;
  vi a(n);
  rep(i,0,n)cin>>a[i];
  rep(i,1,n-1){
    if(a[i]!=a[i-1]&&a[i]!=a[i+1]){
      cout<<i+1<<endl;
      return;
    }
  }
  if(a[0]!=a[1])cout<<1<<endl;
  if(a[n-1]!=a[1])cout<<n<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

