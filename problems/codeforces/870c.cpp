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
using namespace std;

const int N=17;
int q;
ll n,k,ans;
int s[N];

void build(){
  s[1]=-1;
  s[2]=-1;
  s[3]=-1;
  s[4]=1;
  s[5]=-1;
  s[6]=1;
  s[7]=-1;
  s[8]=2;
  s[9]=1;
  s[10]=2;
  s[11]=-1;
  s[12]=3;
  s[13]=2;
  s[14]=3;
  s[15]=2;
  s[16]=4;
}

int main(void){
  fastio;
  build();
  cin>>q;
  while(q--){
    cin>>n;
    if(n<N)ans=s[n];
    else{
      k=(n-13)/4;
      ans=k+s[n-4*k];
    }
    cout<<ans<<endl;
  }
  return 0;
}
