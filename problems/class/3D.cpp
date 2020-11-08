/*
 * Time complexity: O(NlogN+M(logM)^2+NlogM)
 * Explanation: M is the number of queries and stations. N is the number of passengers and intervals.
 * To do the updates and queries of the intervals, we use a fenwick tree. Both operations take O(logM)
 * since M is the size of the tree array. We insert each interval only once because we are using the
 * same ordered tree for all queries, so the global cost of constructing the tree is O(NlogM). It is
 * important to have the tree ordered, so we can correctly use the intervals for each d. This costs
 * O(NlogN). The global cost of checking the tree for the specified intervals is O(M(logM)^2) as a
 * result of the sum of the costs of the M queries. Each query does floor(m/d) queries to check each
 * station and each query costs O(logM), so the global cost is M(M/1+M/2+...+M/d)logM. This can be
 * reduced to M(1/1+1/2+1/3+...+1/M)logM and, finally, MlogMlogM because that sum forms an harmonic
 * number.
 *
 * Space complexity: O(N+M)
 * Explanation: An ordered multiset of N intervals and a fenwick tree of size M.
 *
 * Idea: First, we use a multiset to keep an order in the intervals using its size. This will be
 * useful in the construction of the tree. Then, we need to divide the intervals in two groups:
 * intervals with size < d and intervals with size >= d. A fenwick tree is used to do range updates.
 * We insert the first group in the tree (as a range) and keep the size of the second group. Each
 * position in the tree represents the station and it has the number of intervals that the station
 * intersects. We check the stations that are multiple of d in the tree and sum its value as the
 * number of intervals in the first group. Finally, we sum the value of the first group and the
 * size of the second group. This gives us the value for each query.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=3e5+100; // n<=3e5
const int mmax=1e5+100; // m<=1e5

// i1: intervals with size < d
// i2: intervals with size >= d
int n,m,l,r,d,i1,i2;
int tree[mmax];
multiset<array<int,3>> intervals;

inline int p(int a){
  return a&-a;
}

void update(int a, int b){
  while(a<=m){
    tree[a]+=b;
    a+=p(a);
  }
}

int query(int a){
  int s=0;
  while(a>=1){
    s+=tree[a];
    a-=p(a);
  }
  return s;
}

void update_int(int a, int b){
  update(a,1);
  update(b+1,-1);
}

int query_int(int a){
  return query(a);
}

void debug(){
  cout<<"tree: ";
  rep(i,1,m+1)cout<<tree[i]<<' ';
  cout<<endl;
}

int main(void){
  fastio;
  cin>>n>>m;
  rep(i,0,n){
    cin>>l>>r;
    intervals.insert({r-l,l,r});
  }
  i2=n;
  d=1;
  auto it=intervals.begin();
  while(d<=m&&it!=intervals.end()&&it->front()>=d){
    // all the passengers can be transported if the minimum size is greater or
    // equal than d
    cout<<i2<<endl;
    ++d;
  }
  //cout<<"before"<<endl;
  //debug();
  while(d<=m){
    while(it!=intervals.end()&&it->front()<d){
      auto arr=*it;
      update_int(arr[1],arr[2]);
      ++it;
      --i2;
      //cout<<"update "<<arr[1]<<' '<<arr[2]<<endl;
      //debug();
    }
    i1=0;
    rep(i,1,m/d+1){
      i1+=query_int(i*d);
    }
    cout<<i1+i2<<endl;
    ++d;
  }
  return 0;
}
