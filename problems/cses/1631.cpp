#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
using namespace std;

const int N=2e5;
int n;
ll t,s,mt;

int main(void){
  fastio;
  cin>>n;
  rep(i,0,n){
    cin>>t;
    mt=max(mt,t);
    s+=t;
  }
  cout<<max(2*mt,s)<<endl;
  return 0;
}
