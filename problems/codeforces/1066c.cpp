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
const int N=2e5+1;

void solve(){
  int q;
  cin>>q;
  map<int,int> l,r;
  char c;
  int ans,id;
  cin>>c>>id;
  rep(i,2,q){
    dbg(l);
    dbg(r);
    cin>>c>>id;
    if(c=='L')l[id]=len(l)+1;
    elif(c=='R')r[id]=len(r)+1;
    else{
      if(l.find(id)!=l.end())ans=min(len(l)-l[id],len(r)+l[id]);
      elif(r.find(id)!=r.end())ans=min(len(l)+r[id],len(r)-r[id]);
      else ans=min(len(l),len(r));
      cout<<ans<<endl;
    }
  }
}

int main(){
  fastio;
  solve();
  return 0;
}

