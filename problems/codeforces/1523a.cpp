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
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  
  int i=0;
  while(s[i]=='0'&&i<n){
    ++i;
  }
  if(i<n&&s[i]=='1'){
    rrep(j,i-1,max(i-m,0)){
      s[j]='1';
    }
  }
  dbg(i);
  dbg(s);

  int j,p;
  while(i<n){
    while(s[i]=='1'&&i<n){
      ++i;
    }
    j=i; 
    while(s[j]=='0'&&j<n){
      ++j;
    }
    if(j==n){
      rep(k,i,min(i+m-1,n-1)){
        s[k]='1'; 
      }
    }else{
      p=(j-i)/2; // zeros / 2
      dbg(p);
      if(p!=0){
        rep(k,i,min(i+m-1,i+p-1)){
          s[k]='1'; 
        }
        rrep(k,j-1,max(j-m,j-p)){
          s[k]='1';
        }     
      }
    }
    i=j;
    dbg(i);
    dbg(s);
  }

  cout<<s<<endl;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t)
  solve();
  return 0;
}

