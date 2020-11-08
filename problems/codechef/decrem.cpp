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

int t,l,r;

void solve(){
  cin>>l>>r;
  if(l==1||(l-1)<(r-l)||r/l>1){
    cout<<-1<<endl;
    return;
  }
  cout<<r<<endl;
}

int main(void){
  fastio;
  cin>>t;
  while(t--)solve();
  return 0;
}
