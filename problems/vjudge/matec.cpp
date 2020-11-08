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
const ll mod=1e9+7;
const int nmax=2e5;

int x,n,cnt;
string sx,a,b;
bool digits[10];

void build(){
  int pos=x;
  while(pos>0){
      digits[pos%10]=true;
      pos/=10;
  }
}

bool func(int a){
  while(a>0){
    if(digits[a%10])return true;
    a/=10;
  }
  return false;
}

int main(void){
  fastio;
  cin>>x;
  build();
  n=(int)sqrt(x)+1;
  rep(i,1,n){
    if(x%i==0){
      if(func(i))++cnt;
      if(i!=(x/i)&&func(x/i))++cnt;
    }
  }
  cout<<cnt<<endl;
  return 0;
}
