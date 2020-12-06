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

const int nmax=1e5+5,amax=27;
int t[amax][nmax];
int arr[nmax];
string s;
int n,q;

inline int p(int a){
  return a&-a;
}

void update(int tree[],int a,ll b){
  while(a<=n){
    tree[a]+=b;
    a+=p(a);
  }
}

ll query(int tree[],int a){
  ll acc=0;
  while(a>=1){
    acc+=tree[a];
    a-=p(a);
  }
  return acc;
}

ll query_range(int a,int b){
  ll cnt=0;
  rep(i,0,amax){
    int exist=query(t[i],b)-query(t[i],a-1);
    if(exist)++cnt;
  }
  return cnt;
}

void build(){
  n=len(s);
  rep(i,0,n)update(t[s[i]-'a'],i+1,1);
}

int main(){
  fastio;
  cin>>s; 
  build();
  cin>>q;
  rep(i,0,q){
    char op;
    cin>>op;
    if(op=='1'){
      int pos;
      char c;
      cin>>pos>>c;
      update(t[s[pos-1]-'a'],pos,-1);
      update(t[c-'a'],pos,1);
      s[pos-1]=c;
    }else{
      int l,r;
      cin>>l>>r;
      cout<<query_range(l,r)<<'\n';
    }
  }
  return 0;
}

