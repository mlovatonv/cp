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
#define ret(i,c) for(auto &i:c)
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
  int n,m;
  string s,t;
  cin>>n>>m;
  cin>>s>>t;
  int pos=-1;
  rep(i,0,n-1){
    if(s[i]=='*'){
      pos=i;
      break;
    }
  }

  if(pos==-1){
    cout<<(s==t?"YES":"NO")<<endl;;
    return;
  }

  bool ans=true;
  rep(i,0,pos-1){
    dbg(s[i]);
    dbg(t[i]);
    if(m<=i){
      ans=false;
      break;
    }
    if(s[i]!=t[i]){
      ans=false;
    }
  }
  int j;
  rrep(i,n-1,pos+1){
    dbg(s[i]);
    j=(m-1)-((n-1)-i);
    dbg(t[j]);
    if(j<0){
      ans=false;
      break;
    }
    if(s[i]!=t[j]){
      ans=false; 
    }
  }
  if(j<=(pos-1)){
    ans=false;
  }
  if(ans){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

