#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.s())
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ll=long long;
using vi=vector<int>;

int t,ans;
string x;
int first,s;

int main(){
  fastio;
  cin>>t;
  rep(i,0,t){
    cin>>x;
    first=x[0]-'0';
    s=x.length();
    //cout<<first<<" "<<s<<endl;
    ans=(first-1)*10+s*(s-1)/2+s;
    cout<<ans<<endl;
  }
  return 0;
}

