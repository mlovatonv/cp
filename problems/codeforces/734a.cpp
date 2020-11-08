#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define elif else if
#define rep(i,s,e) for(int i=s;i<e;++i)
#define all(a) a.begin(),a.end()
#define len(a) (a.size())
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
const int nmax=2e5;

int n,d,a;
string s;

int main(void){
  fastio;
  cin>>n;
  cin>>s;
  rep(i,0,n){
    if(s[i]=='A')++a;
    else ++d;
  }
  if(a<d){
    cout<<"Danik"<<endl;
  }elif(d<a){
    cout<<"Anton"<<endl;
  }else{
    cout<<"Friendship"<<endl;
  }
  return 0;
}
