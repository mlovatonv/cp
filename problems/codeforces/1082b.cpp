#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define rep2(i,s,e) for(int i=s;i<e;i+=2)
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
using pii=pair<int,int>;

void solve(){
  int n;
  string s;
  vi segs;
  char c,prevc;
  int segsize=1;
  int segssize;
  int ans=0; // maximum segment length

  cin>>n;
  cin>>s;
  c=prevc=s[0];
  rep(i,1,n){
    c=s[i];
    if(c!=prevc){
      segs.pb(segsize);
      segsize=0;
    }
    ++segsize;
    prevc=c;
  }
  if(segsize)segs.pb(segsize);
  segssize=len(segs);
  ret(i,segs)cout<<"seg"<<i<<endl;
  int gsegs=(segssize-(s[0]=='S'))/2;
  rep2(i,s[0]=='S',segssize){
    if(i<segssize-2&&segs[i+1]==1){
      ans=max(ans,segs[i]+segs[i+2]+(gsegs>2?1:-1));
    }
    ans=max(ans,segs[i]+(gsegs>2?1:0));
  }
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

