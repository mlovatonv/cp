/*
 * Time complexity: O(nlogn)
 * Explanation: Finding the optimum order costs O(nlogn) and computing the minimum swaps 
 * costs O(nlogn).
 *
 * Space complexity: O(n)
 * Explanation: Multiple arrays (including a set) of size 2n are created to store the
 * fenwick tree, the order and the original array.
 *
 * Idea: First, we need to find the optimum order of elements that satisfies Sheldon's
 * requirements. This order can be found in a greedy way by obtaining the corresponding
 * pairs while going over the original array. For example, if the array is 1 2 -3 -2 3,
 * the optimum order would be -1 1 -2 2 -3 3. An ordered set is used to compute the order
 * array because we can use binary search to find the other value of the pair. Then, we
 * need to count the inversions (minimum number of swaps) to reach that optimum order. For
 * every index we need to find the number of elements in the left side [0,index) that are
 * greater than the current element in that index. To do this, we mantain an array that
 * has the elements that have been appearing during the iteration. If it has been visited,
 * it will be marked with a 1. To find how many elements are greater than the current one,
 * we need to sum the values in the range (index,n]. A fenwick tree is used to make these
 * operations faster.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
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

const int nmax=2e5+100;
set<pii> s;
ll arr[nmax],order[nmax],tree[nmax];
int n;
ll ans;

inline int p(int a){
  return a&-a;
}

void update(int a,ll b){
  while(a<=n){
    tree[a]+=b;
    a+=p(a);
  }
}

ll query(int a){
  ll acc=0;
  while(a>=1){
    acc+=tree[a];
    a-=p(a);
  }
  return acc;
}

int main(){
  fastio;
  string ignore;
  cin>>ignore;
  cin>>n;
  n*=2;
  rep(i,0,n){
    cin>>arr[i];
    s.emplace(arr[i],i);
  }
  int cnt=0;
  rep(i,0,n)
    if(order[i]==0){
      int t1=arr[i],t2=-arr[i];
      auto it1=s.lower_bound(mp(t1,-1)),
           it2=s.lower_bound(mp(t2,-1));
      if(t1<0){
        order[it1->se]=++cnt;
        order[it2->se]=++cnt;
      }else{
        order[it2->se]=++cnt;
        order[it1->se]=++cnt;
      }
      s.erase(it1);
      s.erase(it2);
    }
  rep(i,0,n){
    ans+=query(n)-query(order[i]);
    update(order[i],1);
  }
  cout<<ans<<endl;
  return 0;
}

