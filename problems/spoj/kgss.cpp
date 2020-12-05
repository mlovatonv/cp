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
using vi=vector<ll>;

struct node{
  ll a;
  ll b;
  node():a(0),b(0) {}
  node(ll a,ll b):a(a),b(b) {}
  node operator+(node other){
    vi aux={this->a,this->b,other.a,other.b};
    sort(all(aux));
    return {aux[2],aux[3]};
  }
};

const int nmax=1e5+5;
node t[4*nmax];
ll arr[nmax];
int n,q;

void build(int v,int tl, int tr){
  if(tl==tr)t[v]={0,arr[tl]};
  else{
    int tm=(tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    t[v]=t[v*2]+t[v*2+1];
  }
}

void update(int v,int tl,int tr,int pos,ll newval){
  if(tl==tr)t[v]={0,newval};
  else{
    int tm=(tl+tr)/2;
    if(pos<=tm)update(v*2,tl,tm,pos,newval);
    else update(v*2+1,tm+1,tr,pos,newval);
    t[v]=t[v*2]+t[v*2+1];
  }
}

node query(int v,int tl,int tr,int l, int r){
  if(l>r)return {};
  if(l==tl&&r==tr)return t[v];
  int tm=(tl+tr)/2;
  return query(v*2,tl,tm,l,min(r,tm))
         +query(v*2+1,tm+1,tr,max(l,tm+1),r);
}

int main(){
  fastio;
  cin>>n;
  rep(i,0,n)cin>>arr[i];
  build(1,0,n-1);
  cin>>q;
  rep(i,0,q){
    char c;
    int x,y;
    cin>>c>>x>>y;
    if(c=='Q'){
      node r=query(1,0,n-1,x-1,y-1);
      cout<<r.a+r.b<<'\n';
    }else{
      update(1,0,n-1,x-1,y);
    }
  }
  return 0;
}

