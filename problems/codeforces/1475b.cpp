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

int t,n,m,x1,x2;

int main(){
  fastio;
  cin>>t;
  rep(i,0,t){
    cin>>n;
    x1=n/2020;
    m=2020*x1;
    x2=n-m;
    if(x1<x2)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
  return 0;
}

