#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
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

string solve(){
  string ans="A";
  int n;
  cin>>n;
  vi l(n);
  rep(i,0,n-1)cin>>l[i];
  char last;
  rep(i,0,n-1){
    if(i%2==0){ // abc
      rep(j,1,l[i]){
        last=ans[len(ans)-1];
        ans+=last+1;
      }
      last=ans[len(ans)-1];
      if(i<n-1&&(last-'A')<l[i+1]){ // not last
        ans[len(ans)-1]='A'+l[i+1];
      }
    }else{ // cba
      rep(j,1,l[i]){
        ans+='A'+(l[i]-j);
      }
    }
  }
  return ans;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)
    cout<<"Case #"<<i<<": "<<solve()<<endl;
  return 0;
}

