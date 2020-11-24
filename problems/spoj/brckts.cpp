#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define rrep(i,s,e) for(int i=s;i>=e;--i)
#define ret(i,c) for(auto i:c)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
using namespace std;

struct node{
  int l;
  int r;
  node():l(-1),r(-1){}
  node(int l,int r):l(l),r(r){}
  node(char c):l(c=='('),r(c==')'){}
  node operator+(node &other){
    if(other.empty()||this->empty())return *this;
    int m=min(this->l,other.r);
    return {this->l+other.l-m,this->r+other.r-m};
  }
  bool ok(){
    return this->l==0&&this->r==0;
  }
  bool empty(){
    return this->l==-1&&this->r==-1;
  }
};

const int nmax=3e4+5;
int t,n,m,k;
string s;
node tree[nmax*4];

void debug(){
  cout<<"tree=";
  rep(i,1,2*n){
    cout<<i<<"("<<tree[i].l<<" "<<tree[i].r<<") ";
  }
  cout<<endl;
}

void update(int i,node val){
  for(tree[i+=n]=val;i/=2;){
    tree[i]=tree[i<<1]+tree[(i<<1)|1];
  }
}

void query(){
  if(tree[1].ok())printf("YES\n");
  else printf("NO\n");
}

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

void build(){
  int nn=nextPower(n);
  memset(tree,0,nn*2*sizeof(node));
  rep(i,0,n-1){
    tree[nn+i]=node(s[i]);
  }
  rrep(i,nn-1,1){
    tree[i]=tree[i<<1]+tree[(i<<1)|1];
  }
  n=nn;
}

void solve(){
  cin>>n>>s>>m;
  //cout<<s<<endl;
  build();
  //debug();
  printf("Test %d:\n",++t);
  rep(i,1,m){
    cin>>k;
    if(k==0)query();
    else{
      --k;
      s[k]=s[k]=='('?')':'(';
      //cout<<"update: "<<s<<endl;
      update(k,node(s[k]));
      //debug();
    }
  }
}

int main(){
  fastio;
  while(t<10)solve();
  return 0;
}
