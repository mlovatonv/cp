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


int solve(){
  string s;
  cin>>s;
  int n=len(s);
  if(n<2){
    return 0;
  }
  vector<pair<char,int>> v;
  char p=s[0];
  int cnt=1;
  rep(i,1,n-1){
    if(s[i]!=p){
      v.pb({p,cnt});
      p=s[i];
      cnt=1;
    }else{
      ++cnt;
      continue; 
    }
  }
  v.pb({p,cnt});

  int m=len(v);
  
  if(m%2==0){
    return 0;
  }

  int mid=m/2;
  
  rep(i,1,mid){
    if(v[mid+i].fi!=v[mid-i].fi||
       (v[mid+i].se+v[mid-i].se)<3){
      return 0;
    }
  }

  return v[mid].se>=2?v[mid].se+1:0;
}

int main(){
  fastio;
  cout<<solve()<<endl;
  return 0;
}

