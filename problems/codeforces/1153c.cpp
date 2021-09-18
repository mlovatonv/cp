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
  int n;
  cin>>n;
  string s;
  cin>>s;

  if(n%2||s[0]==')'||s[n-1]=='('){
    cout<<":("<<endl;
    return;
  }
  s[0]='('; 
  s[n-1]=')';
 
  int cnt=0;
  rep(i,0,n-1)if(s[i]=='(')++cnt; 
  cnt=n/2-cnt;
  rep(i,0,n-1){
    if(s[i]=='?'){
      if(cnt){
        s[i]='(';
        --cnt;
      }else{
        s[i]=')';
      }
    }
  }

  bool valid=true;
  stack<char> st;
  rep(i,0,n-1){
    if(s[i]=='('){
      st.push(s[i]);
    }else{
      if(st.empty()){
        valid=false;
        break;
      }else{
        st.pop();
      }
    }
  }
  if(!st.empty()){
    valid=false;
  }
  int acc=0;
  rep(i,0,n-1){
    if(s[i]=='(')++acc;
    else --acc;
    if(acc==0&&i<n-1){
      valid=false;
      break;
    }
  }

  if(valid){
    cout<<s<<endl;
  }else{
    cout<<":("<<endl;
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

