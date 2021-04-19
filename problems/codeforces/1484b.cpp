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
const int s=1e6;
int t,n;
ll a,pa,pos,neg,fa,m,c,sa,ma;
ll arr[s];

void solve(){
  cin>>n;
  // m c s
  // all must be positive
  // 0 <= c < m
  // a1 = s mod m
  // ai = (ai-1 + c) mod m
  // ai <= 1e9
  neg=1;
  pos=-1;
  rep(i,0,n)cin>>arr[i];
  fa=arr[0]; // first a
  sa=arr[1]; // second a
  ma=arr[0]; // max a
  if(n<3){cout<<0<<'\n';return;}
  rep(i,1,n){
    a=arr[i];
    pa=arr[i-1]; // previous a
    ll diff=a-pa;
    if(0<diff){
      if(pos!=-1&&pos!=diff){cout<<-1<<'\n';return;}
      else pos=diff;
    }elif(diff<0){
      if(neg!=1&&neg!=diff){cout<<-1<<'\n';return;}
      else neg=diff;
    }else{
      if((pos==-1&&neg==1)||(pos==0&&neg==0))pos=neg=0;
      else{cout<<-1<<'\n';return;}   
    }
    ma=max(ma,a);
  }

  m=pos-neg;
  c=pos;
  cout<<"sa:"<<sa<<" c:"<<c<<" fa:"<<fa<<" m:"<<m<<endl;
  if(pos==0&&neg==0)cout<<0<<'\n'; // all numbers are the same
  elif(pos!=-1&&neg==1)cout<<0<<'\n'; // incrementing sequence
  elif(pos==-1&&neg!=1)cout<<0<<'\n'; // decrementing sequence
  elif(m<=ma||sa!=(fa+c)%m)cout<<-1<<'\n'; // m <= first a and sa != (fa + c) mod m
  else cout<<m<<' '<<c<<'\n'; // m c
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

