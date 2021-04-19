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
ll n;

int main(){
  fastio;
  cin>>t;
  rep(i,0,t){
    cin>>n;
    if(n%2)cout<<"YES"<<endl;
    else{
      if(n&(n-1))cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
  }
  return 0;
}

