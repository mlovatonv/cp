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

int n,q;
ll x[nmax],t[nmax];

inline int p(int a){
  return a&-a;
}

void update(int a,ll b){
  while(a<=n){
    t[a]+=b;
    a+=p(a);
  }
}

ll query(int a){
  ll s=0;
  while(a>=1){
    s+=t[a];
    a-=p(a);
  }
  return s;
}

int main(void){
  fastio;
  cin>>n>>q;
  rep(i,1,n){
    cin>>x[i];
    update(i,x[i]);
  }
  while(q--){
    char qq;
    int a;
    ll b;
    cin>>qq>>a>>b;
    if(qq=='1')update(a,b-x[a]),x[a]=b;
    else cout<<query(b)-query(a-1)<<endl;
  }
  return 0;
}
