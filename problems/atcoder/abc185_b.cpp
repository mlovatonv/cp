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

ll n,nmax,t,l,r,m,p,a,b;

int main(){
  fastio;
  cin>>nmax>>m>>t;
  n=nmax;
  rep(i,0,m){
    cin>>a>>b;
    l=a-p;
    if(l>=nmax){
      cout<<"No"<<endl;
      return 0;
    }
    r=b-a;
    p=b;
    n+=(r-l);
    n=min(n,nmax);
    if(n<=0){
      cout<<"No"<<endl;
      return 0;
    }
  }
  n-=(t-p);
  n=min(n,nmax);
  if(n<=0)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  return 0;
}

