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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef vector<piii> vi;

const int nmax=1e3+10;
int suffix[nmax],labels[2*nmax],n,q;
string s,patron;

void build(){
  n=len(s);
  rep(i,0,n)labels[i]=s[i]-'A';
  for(int k=0;k<n;(k==0)?k=1:k*=2){
    vi aux;
    rep(i,0,n)
      aux.pb({{labels[i],labels[i+k]},i});
    sort(all(aux));
    int cont=0;
    rep(i,0,n){
      int pos=aux[i].se;
      if(i>0&&aux[i].fi!=aux[i-1].fi)++cont;
      labels[pos]=cont+1;
    }
    if(cont==n-1)break;
  }
  rep(i,0,n)suffix[labels[i]-1]=i;
}

int main(){
  fastio;
  cin>>n>>q;
  cin>>s;
  build();
  while(q--){
    cin>>patron;
    int low=0;
    int up=n-1;
    bool exist=true;
    int begin1,end1,mid1,valmid1;
    int begin2,end2,mid2,valmid2;
    for(int k=0;k<patron.size();++k){
      begin1=low;
      end1=up;
      exist=false;
      while(begin1<=end1||begin2<=end2){
        //primera aparicion
        if(begin1<=end1){
          mid1=(begin1+end1)/2;
          valmid1=s[suffix[mid1]+k];
          if(valmid1==patron[k]){
            exist=true;
            end1=mid1-1;
          }
          if(valmid1<patron[k]){
            begin1=mid1+1; 
          }
          if(valmid1>patron[k]){
            end1=mid1-1; 
          }
        }
        //ultima aparicion
        if(begin2<=end2){
          mid2=(begin2+end2)/2;
          valmid2=s[suffix[mid2]+k];
          if(valmid2==patron[k]){
            exist=true;
            begin2=mid2+1;
          }
          if(valmid2<patron[k]){
            begin2=mid2+1; 
          }
          if(valmid2>patron[k]){
            end2=mid2-1; 
          }
        }
      }
      // si no existe, entonces ya no buscamos
      if(!exist)break;
      low=begin1;
      up=end2;
    }
    if(exist)printf("%d\n",up-low+1);
    else printf("0\n");
  }
  return 0;
}
