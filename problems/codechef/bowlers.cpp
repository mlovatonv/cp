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

int t,n,k,l;

int main(void){
  fastio;
  cin>>t;
  while(t--){
    cin>>n>>k>>l;
    if(k*l<n||(k==1&&n>1))cout<<-1<<endl;
    else{
      int i=0;
      while(n--){
        cout<<++i<<' ';
        i%=k;
      }
      cout<<endl;
    }
  }
  return 0;
}
