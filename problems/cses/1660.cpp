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

const int N=2e5+5;
int n,cnt;
ll x,a,s;
map<ll,bool> m;

int main(void){
  fastio;
  cin>>n>>x;
  m[0]=true;
  rep(i,0,n){
    cin>>a;
    s+=a;
    if(m.find(s-x)!=m.end()&&m[s-x])++cnt;
    m[s]=true;
  }
  cout<<cnt<<endl;
  return 0;
}
