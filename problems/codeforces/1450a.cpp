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

int t,n,m=4;
string s,ss="trygub";

int main(){
  fastio;
  cin>>t;
  rep(i,0,t){
    cin>>n;
    cin>>s;
    sort(all(s));
    cout<<s<<endl;
  }
  return 0;
}

