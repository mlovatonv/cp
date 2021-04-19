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

void solve(){
  int n,x,t,ops=0,maxops;
  cin>>n;
  maxops=2*n;
  set<int> hand;
  queue<int> pile;
  rep(i,0,n){
    cin>>x;
    hand.insert(x);
  }
  rep(i,0,n){
    cin>>x;
    pile.push(x);
  }
  while(true){ // until I find 1 in my hand
    if(hand.find(1)!=hand.end()){
      break;
    }else{ // maybe it fails ?
      pile.push(0);
      t=pile.front();
      pile.pop();
      hand.insert(t);
      ++ops;
    }
  }
  
  rep(i,0,maxops-ops){
    set<int> hand2(hand);
    queue<int> pile2(pile);
    rep(j,0,i){
      pile2.push(0);
      t=pile2.front();
      pile2.pop();
      hand2.insert(t);
      ++ops;  
    }
    rep(i,2,n+1){
      cout<<"for "<<i<<endl;
      if(hand.find(i)!=hand.end()){
        cout<<"found "<<i<<endl;
        hand.erase(i);
        pile.push(i);
        t=pile.front();
        pile.pop();
        hand.insert(t);
        cout<<"pop "<<t<<endl;
      }else{
        cout<<2*n<<endl;
        return; 
      }
      ++ops;
    } 
  }
  cout<<ops<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

