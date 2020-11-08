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
const int N=1e5+10;

int n,q,a,b,u,v,c,t;
int A[2*N];
ll T[4*N],Z[4*N];

void build(){
  memset(A,0,2*N*sizeof(int));
  memset(T,0,4*N*sizeof(ll));
  memset(Z,0,4*N*sizeof(ll));
}

//https://graphics.standford.edu/~seander/bithacks
int nextPower(int v){
  --v;
  v|=v>>1;
  v|=v>>2;
  v|=v>>4;
  v|=v>>8;
  v|=v>>16;
  ++v;
  return v;
}

void update(int a,int b,int k,int x,int y,int u){
  if(b<x||y<a)return;//[a,b] no se intersecta con [x,y]
  if(a<=x&&b<=y){//[x,y] esta incluido en [a,b]
    Z[k]+=u;
    return;
  }
  //se intersecta pero no esta incluido
  Z[2*k]+=Z[k];
  Z[2*k+1]+=Z[k];
  Z[k]=0;
  int d=(x+y)/2;
  update(a,b,2*k,x,d,u);
  update(a,b,2*k+1,d+1,y,u);
  //numero de hojas es elementos en el rango y-x+1
  T[k]=T[2*k]+Z[2*k]*(d-x+1)+T[2*k+1]+Z[2*k+1]*(y-(d+1)+1);
}

ll suma(int a,int b,int k,int x,int y){
  if(b<x||a>y)return 0;
  if(a<=b&&y<=b)return T[k]+(y-x+1)*Z[k];
  Z[2*k]+=Z[k];
  Z[2*k+1]+=Z[k];
  Z[k]=0;
  int d=(x+y)/2;
  ll s1=suma(a,b,2*k,x,d);
  ll s2=suma(a,b,2*k+1,d+1,y);
  T[k]=T[2*k]+Z[2*k]*(d-x+1)+T[2*k+1]+Z[2*k+1]*(y-(d+1)+1);
  return s1+s2;
}

void solve(){
  build();
  cin>>n>>q;
  n=nextPower(n);
  while(q--){
    cin>>c;
    switch(c){
      case 0: cin>>a>>b>>u;
              update(min(a-1,b-1),max(a-1,b-1),1,0,n-1,u);
              break;
      case 1: cin>>a>>b;
              cout<<suma(min(a-1,b-1),max(a-1,b-1),1,0,n-1);
              break;
    }
  }
}

int main(void){
  fastio;
  cin>>t;
  while(t--)solve();
  return 0;
}
