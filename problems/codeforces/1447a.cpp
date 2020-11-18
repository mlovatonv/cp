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
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
const int nmax=2e5;
int t,n;

int main(){
  fastio;
  cin>>t;
  rep(i,0,t){
    cin>>n;
    cout<<n<<endl;
    rep(i,1,n+1){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}
