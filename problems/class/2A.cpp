/*
 * Time complexity: O(n^2)
 * Explanation: Sorting the array (nlogn) + Looping through elements and in
 * each loop n-1 elements are checked (n^2)
 *
 * Space complexity: O(n)
 * Explanation: n elements are stored
 *
 * Idea: Sort the n elements and, then, check the lesser and greater neighbors
 * of each element. Continue until a correct triple is found; otherwise,
 * return -1. Some invalid cases are checked before the looping.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;++i)
#define fi first
#define se second
using namespace std;

const int N=5005;
int n,l,r,s;
ll x;
pair<ll,int> a[N];

int main(void){
  fastio;
  cin>>n>>x;
  rep(i,0,n){cin>>a[i].fi;a[i].se=i;};
  if(n<3){cout<<"-1"<<endl;return 0;}
  sort(a,a+n);
  if(a[n-1].fi+a[n-2].fi+a[n-3].fi<x){cout<<"-1"<<endl;return 0;}
  rep(i,1,n-1) {
    l=0;
    r=n-1;
    while(l<r&&l<i&&i<r){
      s=a[l].fi+a[i].fi+a[r].fi;
      if(s==x){cout<<a[l].se+1<<' '<<a[i].se+1<<' '<<a[r].se+1<<endl;return 0;}
      else if(s<x)++l;
      else --r;
    }
  }
  cout<<"-1"<<endl;
  return 0;
}
