#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll pow10[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int l,r,maxi,p,m;

ll getweight(ll x){
  ll aux=x,dec=1,r=0;
  while(aux>0){
    r+=(9-aux%10LL)*dec;
    aux/=10LL;
    dec*=10LL;
  }
  return r*x;
}

int main(void){
  fastio;
  cin>>l>>r;
  p=pow10[(int)ceil(log10(r))];
  m=p/2;
  if(r==p){
    maxi=p;
  }elif(m<l){
    maxi=l;
  }elif(r<m){
    maxi=r;
  }else{
    maxi=m;
  }
  //cout<<"maxi="<<maxi<<endl;
  cout<<getweight(maxi)<<endl;
  return 0;
}
