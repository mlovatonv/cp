#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;++i)
#define fi first
#define se second
using namespace std;

const int N=1e4+5;
int t,n,m,as,op,iavg;
double avg;
ll a[N];

int main(void){
  fastio;
  cin>>t;
  while(t--){
    cin>>n>>m;
    as=n*m;
    avg=0;
    op=0;
    rep(i,0,as){
      cin>>a[i];
      avg+=a[i]/(double)as;
    }
    iavg=round(avg);
    cout<<"avg="<<avg<<" iavg="<<iavg<<" as="<<as<<endl;
    rep(i,0,as){
      op+=abs(iavg-a[i]);
    }
    cout<<op<<endl;
  }
  return 0;
}
