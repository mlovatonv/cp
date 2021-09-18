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
  map<int,int> m;
  int a;
  while(cin>>a)++m[a];
  int ans;
  if(len(m)==0){
    ans=-1;
  }elif(len(m)==1){
    ans=m.begin()->fi;
  }else{
    ans=m.begin()->fi;
    int mx_acc=0;
    int acc=0;
    for(auto it=++m.begin();it!=m.end();++it){
      acc+=it->fi*it->se;
    }
    mx_acc=max(mx_acc,acc);
    for(auto it=++m.begin();it!=m.end();++it){
      acc-=it->fi*it->se;
      --it;
      acc+=it->fi*it->se;
      ++it;
      if(acc>=mx_acc){
        ans=it->fi;
        mx_acc=acc;
      }
    }
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

