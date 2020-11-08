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

int n,x;
stack<pair<int,int>> s;

int main(void){
  fastio;
  cin>>n;
  s.push({INT_MAX,0});
  rep(i,1,n+1){
    cin>>x;
    while(!s.empty()&&x<=s.top().fi)s.pop();
    if(s.empty())cout<<0<<' ';
    else cout<<s.top().se<<' ';
    s.push({x,i});
  }
  cout<<endl;
  return 0;
}
