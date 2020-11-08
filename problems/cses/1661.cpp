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
int n;
ll x,a,s,cnt;
map<ll,int> m;

int main(void){
  fastio;
  cin>>n>>x;
  m[0]=1;
  rep(i,0,n){
    cin>>a;
    s+=a;
    if(m.find(s-x)!=m.end())cnt+=m[s-x];
    ++m[s];
  }
  cout<<cnt<<endl;
  return 0;
}
