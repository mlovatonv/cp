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
using pii=pair<int,int>;

pii divi(pii a,pii b){
  return {a.fi*b.se,a.se*b.fi};
}

pii mult(pii a,pii b){
  return {a.fi*b.fi,a.se*b.se};
}

pii rest(pii a){
  return {a.se-a.fi,a.se};
}

pii fmin(pii a,pii b){
  if(a.fi<0||a.se<0||a.se<a.fi){
    return b;
  }
  return ((double)a.fi/a.se)<((double)b.fi/b.se)?a:b;
}

pii clean(pii a){
  int g;
  while((g=gcd(a.fi,a.se))!=1){
    a.se/=g;
    a.fi/=g;
  }
  return a;
}

void solve(){
  vector<pii> v(4,{0,1});
  rep(i,0,3)cin>>v[i].fi;
  pii ans={1e9,1};
  // 1x2 3x4
  // d[i] = opposite dimension 1->3
  // r[i] = opp opp dimension 1->4
  // c[i] = couple 1->2
  int d[4]={2,3,0,1},r[4]={3,2,1,0},c[4]={1,0,3,2};
  rep(i,0,3){
    pii t=rest(
          divi(
            mult(v[r[i]],
              divi(v[i],
                v[d[i]]
              )
            ),
            v[c[i]]
          )
        );
    dbg(t);
    ans=fmin(t,ans);
  }
  ans=clean(ans);
  cout<<ans.fi<<"/"<<ans.se<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

