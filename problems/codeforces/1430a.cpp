#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;

int t,n;

int main(void){
  fastio;
  cin>>t;
  while(t--){
    cin>>n;
    vector<int> v;
    bool pos=false;
    if(n>2){
      if(n%2==0){
        pos=true;
      }
      while(n%2==0){
        
      }
    }


    bool pos=false;
    if(n%3==0){
      n=n/3;
      v.pb(n);
      pos=true;
    }else v.pb(0);
    if(n%5==0){
      n=n/5;
      v.pb(n);
      pos=true;
    }else v.pb(0);
    if(n%7==0){
      n=n/7;
      v.pb(n);
      pos=true;
    }else v.pb(0);
    if(!pos) cout<<-1<<endl;
    else{
      for(auto& i:v)cout<<i<<' ';
      cout<<endl;
    }
  }
  return 0;
}
