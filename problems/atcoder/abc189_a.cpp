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

int main(){
  fastio;
  string s;
  cin>>s;
  rep(i,1,len(s))
    if(s[i]!=s[i-1]){
      cout<<"Lost"<<endl;
      return 0;
    }
  cout<<"Won"<<endl;
  return 0;
}

