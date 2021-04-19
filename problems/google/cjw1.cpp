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


int solve(){
  int n;
  cin>>n;
  set<int> s;
  map<int,int> occ;
  rep(i,0,n-1){
    int a;
    cin>>a;
    s.insert(a);
    if(occ.find(a)==occ.end()){
      occ[a]=0;
    }
    ++occ[a];
  }
  int i=1;
  int ans=0;
  ret(j,s){
    ans+=occ[j]*i;
    ++i;
  }
  return ans;
}

int main(){
  fastio;
  int t;
  cin>>t;
  rep(i,1,t){
    cout<<"Case #"<<i<<": "<<solve()<<endl; 
  }
  return 0;
}

