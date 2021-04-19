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

int ans,a,b,prevp,p,n,preva,prevb;

int main(){
  fastio;
  cin>>n;
  preva=a=1,prevb=b=n;
  while(true){
    if(b-a==1){ // partition of size 2
      ans=a==prevp?b:a;
      break;
    }
    cout<<"? "<<a<<' '<<b<<'\n';
    cout.flush();
    cin>>p; // get second maximum's position
    if(prevp==p||!prevp){
      a=p<=b/2?a:b/2+1;
      b=p<=b/2?b/2:b;
      prevp=p;
    }else{
      a=preva;
      b=prevb;
      cout<<"prevp="<<prevp<<" a="<<a<<" b="<<b<<endl;
      a=prevp<=b/2?b/2+1:a;
      b=prevp<=b/2?b:b/2;
      prevp=0;
    }
    preva=a;
    prevb=b;
  }
  cout<<"! "<<ans<<'\n';
  cout.flush();
  return 0;
}

