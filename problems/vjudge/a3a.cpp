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

int t;
string s;

bool isp(){
  int l=0;
  int r=s.size()-1;
  while(l<r){
    if(s[l++]!=s[r--])return false;
  }
  return true;
}

void solve(){
  cin>>s;
  if(isp()){
    s=s.back()+s;
    s.pop_back();
    if(isp())cout<<"-1\n";
    else cout<<s<<'\n';
  }else{
    cout<<s<<'\n';
  }
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}
