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

int t;

char foo(char a,char b){
  if(a==b){
    if(a=='a')return 'b';
    if(a=='b')return 'c';
    if(a=='c')return 'a';
  }
  if(
      (a=='a'&&b=='b')||
      (a=='b'&&b=='a')
    ){
    return 'c';
  }
  if(
      (a=='a'&&b=='c')||
      (a=='c'&&b=='a')
    ){
    return 'b';
  }
  if(
      (a=='c'&&b=='b')||
      (a=='b'&&b=='c')
    ){
    return 'a';
  }
  return 'a';
}

void solve(){
  string s;
  cin>>s;
  int n=len(s);
  if(s[0]=='?'){
    if(n&&s[1]!='?'){
      s[0]=foo(s[1],s[1]);
    }else{
      s[0]='a';
    }
  }
  rep(i,1,n-2){
    if(s[i]=='?'){
      if(s[i+1]!='?'&&s[i-1]!='?'){
        s[i]=foo(s[i+1],s[i-1]);
      }else{
        s[i]=foo(s[i-1],s[i-1]);
      }
    }
  }
  if(s[n-1]=='?'){
    s[n-1]=foo(s[n-2],s[n-2]);
  }
  rep(i,0,n-2){
    if(s[i]==s[i+1]){
      cout<<-1<<endl;
      return;
    }
  }
  cout<<s<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,1,t)solve();
  return 0;
}

