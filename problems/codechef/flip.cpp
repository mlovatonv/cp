#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const ll mod=1e9+7;
const int nmax=2e5;

int t,n;
string s1,s2;

void solve(){
  cin>>s1>>s2;
  n=len(s1);
  unordered_map<int,bool> m;
  int ans=0;
  int prev=-1;
  rep(i,0,n){
    if(s1[i]!=s2[i]){
      if(!m[i-2])++ans;
      m[i]=true;
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
