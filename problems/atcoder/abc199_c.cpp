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
  string s;
  cin>>s;
  int q;
  cin>>q;
  string first=s.substr(0,n);
  string second=s.substr(n,n);
  dbg(first+second);
  rep(i,1,q){
    int t,a,b;
    cin>>t>>a>>b;
    --a,--b;
    if(t==1){
      if(a<n&&b<n){
        swap(first[a],first[b]);
      }elif(n<=a&&n<=b){
        swap(second[a-n],second[b-n]); 
      }else{
        swap(first[a],second[b-n]);
      }
    }else{
      swap(first,second); 
    }
    dbg(first+second);
  }
  cout<<first+second<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

