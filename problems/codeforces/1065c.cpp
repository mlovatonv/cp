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

const int nmax=2e5+10;
const int realn=2e5+5;
ll ft[nmax]; // The following implementation uses one-based indexing.

void add(int idx,ll val){
  for(++idx;idx<realn;idx+=idx&-idx){
    ft[idx]+=val;
  }
}

void range_add(int l,int r,ll val){
  add(l,val);
  add(r+1,-val);
}

ll point_query(int idx){
  ll ans=0;
  for(++idx;idx>0;idx-=idx&-idx){
    ans+=ft[idx];
  }
  return ans;
}

void solve(){
  int n,k;
  cin>>n>>k;
  vi h(n+1);
  rep(i,1,n){
    cin>>h[i];
    range_add(1,h[i],1);
  }
  int maxh=*max_element(all(h));
  h[0]=maxh; 
  int minh=*min_element(all(h));
  dbg(maxh);
  dbg(minh);
  ll acc=0,ans=0,pq=0;
  dbg(h);
  rrep(i,maxh,minh+1){
    pq=point_query(i);
    dbg(pq);
    if((acc+pq)>k){
      ++ans;
      dbg(ans);
      acc=0;
    }
    acc+=pq;
  }
  if(acc)++ans;
  cout<<ans<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

