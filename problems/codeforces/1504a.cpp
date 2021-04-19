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
string s;

void solve(){
  cin>>s;
  s+='a';
  if(s==string(s.rbegin(),s.rend()))s.pop_back();
  else{
    cout<<"YES"<<endl<<s<<endl;
    return; 
  }
  s='a'+s;
  if(s==string(s.rbegin(),s.rend()))cout<<"NO"<<endl;
  else cout<<"YES"<<endl<<s<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

