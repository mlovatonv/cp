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
const int nmax=2e5;
int t,n,q,x,y;
int tree[nmax];
string s;
char c;

inline int p(int a){
  return a&-a;
}

void update(int a, int b){
  while(a<=n){
    tree[a]+=b;
    a+=p(a);
  }
}

int query(int a){
  int su=0;
  while(a>=1){
    su+=tree[a];
    a-=p(a);
  }
  return su;
}

void update_int(int a, int b){
  update(a,1);
  update(b+1,-1);
}

void build(){
  rep(i,1,n+1)tree[i]=0;
  update(1,s[0]-'0');
  rep(i,1,n)update(i+1,s[i]-s[i-1]);
}

void solve(){
  cin>>s;
  cin>>q;
  n=s.size();
  build();
  rep(i,0,q){
    cin>>c;
    if(c=='I'){
      cin>>x>>y;
      update_int(x,y);
    }else{
      cin>>x;
      printf("%d\n",query(x)%2);
    }
  }
}

int main(void){
  fastio;
  cin>>t;
  rep(i,0,t){
    printf("Case %d:\n",i+1);
    solve();
  }
  return 0;
}
