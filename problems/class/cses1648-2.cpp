#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=2e5+1;

char c;
int n,q,q1,q2;
ll x[nmax],tree[2*nmax];

void update(int a,ll b){
  a=a+n;
  tree[a]=b;
  a/=2;
  while(a>=1){
    tree[a]=tree[2*a]+tree[2*a+1];
    a/=2;
  }
}

void build(){
  rep(i,1,n){
    update(i,x[i]);
  }
}

ll suma(int a,int b){
  ll s=0;
  a=a+n;
  b=b+n;
  while(a<=b){
    if(a%2!=0){
      s+=tree[a];
      ++a;
    }
    if(b%2==0){
      s+=tree[b];
      --b;
    }
    a/=2;
    b/=2;
  }
  return s;
}

int main(void){
  fastio;
  cin>>n>>q;
  rep(i,1,n)cin>>x[i];
  build();
  while(q--){
    cin>>c>>q1>>q2;
    if(c=='1'){
      update(q1,q2);
    }else{
      cout<<suma(q1,q2)<<endl;
    }
  }
  return 0;
}
