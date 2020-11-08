#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;

int n,r,c,a,b,l,ans=INT_MAX;
string s;
map<int,bool> land,vis;
vector<int> va,vb;

int dist(int a1,int b1){
  int x1=a1/n,y1=a1%n,x2=b1/n,y2=b1%n,x=x1-x2,y=y1-y2;
  return x*x+y*y;
}

bool search(int x,bool isa){
  if(x<0||l<x||!land[x]||vis[x])return false;
  if(isa) va.pb(x);
  else vb.pb(x);
  vis[x]=true;
  bool result=false;
  if(x%n!=0)result|=search(x-1,isa);
  if(x%n!=n-1)result|=search(x+1,isa); 
  return result||search(x-n,isa)||search(x+n,isa)||x==b;
}

inline int p(int x,int y){
  return x*n+y;
}

int main(void){
  fastio;
  cin>>n;
  l=n*n-1;
  cin>>r>>c;
  a=p(r-1,c-1);
  cin>>r>>c;
  b=p(r-1,c-1);
  rep(i,0,n){
    cin>>s;
    rep(j,0,n)if(s[j]=='0')land[p(i,j)]=true;
  }
  if(search(a,true))cout<<0<<endl;
  else{
    search(b,false);
    for(auto& i:va)for(auto& j:vb)ans=min(ans,dist(i,j));
    cout<<ans<<endl;
  }
  return 0;
}
