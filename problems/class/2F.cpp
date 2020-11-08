/*
 * Time complexity: O(nlogn)
 * Explanation: For each element, a binary search is executed to find the
 * function that minimizes the element. Also, n intersections are calculated
 * and inserted to the intervals vector, each insertion costs O(1) amortized.
 *
 * Space complexity: O(n)
 * Explanation: n elements and n intervals (at maximum) are stored.
 *
 * Idea: Find the minimum value for each element using the convex hull
 * trick.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define ld long double
#define pi pair<ld,int>
#define rep(i,s,e) for(int i=s;i<e;++i)
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(),a.end()
using namespace std;

const int N=2e5+5;
const ld F=numeric_limits<ld>::max();
int n;
ll a[N];
vector<pi> ivals;

ld intersection(int i, int j){
  ld s=a[i]-a[j],r=1LL*i*i-1LL*j*j,d=1LL*2*i-1LL*2*j;
  return s/d + r/d;
}

int main(void){
  fastio;
  cin>>n;
  rep(i,1,n+1)cin>>a[i];
  ivals.push_back({F,1});
  rep(i,2,n+1){
    while(!ivals.empty()){
      int m=ivals.size();
      int idx=ivals[m-1].se;
      ld xx=intersection(i,idx);
      //cout<<"xx="<<xx<<endl;
      if(m>1&&xx<ivals[m-2].fi){
        //cout<<"pop_back "<<ivals[m-2].fi<<endl;
        ivals.pop_back();
      }else{
        m=ivals.size();
        ivals[m-1].fi=xx;
        ivals.push_back({F,i});
        break;
      }
    }
  }
  //for(auto x:ivals){
  //  cout<<x.fi<<' '<<x.se<<endl;
  //}
  rep(i,1,n+1){
    ld x=i;
    auto idx=lower_bound(all(ivals),mp(x,0))-ivals.begin();
    //cout<<"idx="<<idx<<endl;
    int j=ivals[idx].se;
    //cout<<"aj="<<a[j]<<" i="<<i<<" j="<<j<<endl;
    ll ans=a[j]-1LL*2*i*j;
    ans+=1LL*j*j+1LL*i*i;
    cout<<ans<<endl;
  }
  return 0;
}
