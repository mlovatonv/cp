/*
 * Time complexity: O(nlogn+klogn)
 * Explanation: We do n updates and each update costs O(logn) because it is a segment tree with logn
 * levels. Also, we do k queries and each query costs O(logn) for the same reason.
 *
 * Space complexity: O(n)
 * Explanation: 1 array of n elements is used to store the values and 1 array of 2n elements is used
 * to store the tree.
 *
 * Idea: Use a segment tree to get the maximum value between A (inclusive) and B (exclusive). If the
 * maximum value is greater than the value in A, it is not possible to get to B.
 */

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define rrep(i,s,e) for(int i=s;i>e;--i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=5e4+100;

int n,q,A,B,S,E,cnt;
int h[nmax],tree[2*nmax];

void build(){
  rep(i,0,n){
    tree[i+n]=h[i];
  }
  rrep(i,n-1,0){
    tree[i]=max(tree[i*2],tree[i*2+1]);
  }
}

int maximo(int a,int b){
  a=a+n;
  b=b+n;
  int m=0;
  while(a<=b){
    if(a%2!=0){
      m=max(m,tree[a]);
      ++a;
    }
    if(b%2==0){
      m=max(m,tree[b]);
      --b;
    }
    a/=2;
    b/=2;
  }
  return m;
}

int main(void){
  fastio;
  cin>>n>>q;
  rep(i,0,n)cin>>h[i];
  build();
  while(q--){
    cin>>A>>B;
    if(A>B)S=B+1,E=A;
    elif(A<B)S=A,E=B-1;
    else S=E=A;
    if(maximo(S-1,E-1)<=h[A-1])++cnt;
    // cout<<"A="<<A<<" B="<<B<<" S="<<S<<" E="<<E<<" max="<<maximo(S-1,E-1)<<endl;
  }
  cout<<cnt<<endl;
  return 0;
}
