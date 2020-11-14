#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;

int n,k,id;
deque<int> q;

void solve(){
  for(auto j:q){
    if(j==id)return; 
  }
  if(q.size()==k){
    q.pop_back();
  }
  q.push_front(id);
}

int main(void){
  fastio;
  cin>>n>>k;
  rep(i,0,n){
    cin>>id;
    solve(); 
  }
  cout<<q.size()<<endl;
  while (!q.empty()){
    cout<<q.front()<<" ";
    q.pop_front();
  }
  cout<<endl;
  return 0;
}
