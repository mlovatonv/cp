#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=2e5;

int t,n;
string s;

void solve(){
  cin>>n;
  cin>>s;
  char c=s[n-1];
  rep(i,0,n-1){
    if(c==s[i]){
      cout<<"YES"<<endl;
      return;
    }
  }
  cout<<"NO"<<endl;
}

int main(void){
  fastio;
  cin>>t;
  while(t--)solve();
  return 0;
}
