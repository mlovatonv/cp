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


void solve(){
  int n;
  cin>>n;
  set<int> s;
  rep(i,1,n){
    int a;
    cin>>a;
    s.insert(a);
  }
  if(len(s)>3){
    cout<<-1<<endl;
    return;
  }
  if(len(s)==1){
    cout<<0<<endl;
    return;
  }
  int diff=*s.rbegin()-*s.begin();
  if(len(s)==3){
    if(diff%2==0&&*(++s.begin())==(*s.begin()+diff/2)){
      cout<<diff/2<<endl;
    }else{
      cout<<-1<<endl;
    }
  }else{
    if(diff%2){
      cout<<diff<<endl;
    }else{
      cout<<diff/2<<endl;
    }
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

