#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define elif else if
#define rrep(i,s,e) for(int i=s;i>=e;--i)
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

int t,n;
string a,b;

void solve(){
  cin>>n>>a>>b;
  if(a==b){
    cout<<"YES"<<endl;
    return;
  }
  int aOnes=0,aZeros=0,bOnes=0,bZeros=0,lastEq=-1,lastNeq=-1;
  bool isInvalid;
  rrep(i,n-1,0){
    //cout<<"lastEq="<<lastEq<<" lastNeq="<<lastNeq<<endl;
    //cout<<aOnes<<" "<<bOnes<<" "<<aZeros<<" "<<bZeros<<endl;
    if(a[i]==b[i]){
      if(lastNeq==i+1){ // judging neq interval
        isInvalid=aOnes!=aZeros; // number of ones and zeros must be eq
        if(isInvalid){
          cout<<"NO"<<endl;
          return;
        }
        aOnes=aZeros=bOnes=bZeros=0;
      }
      lastEq=i;
    }else{
      if(lastEq==i+1){ // judging eq interval
        isInvalid=lastNeq!=-1&&aOnes!=aZeros; // number of ones and zeros must be eq
        // and no neq interval before 
        if(isInvalid){
          cout<<"NO"<<endl;
          return;
        }
        aOnes=aZeros=bOnes=bZeros=0;
      }
      lastNeq=i; 
    }
    if(a[i]=='1')++aOnes;
    else ++aZeros;
    if(b[i]=='1')++bOnes;
    else ++bZeros;
  }
  //cout<<"lastEq="<<lastEq<<" lastNeq="<<lastNeq<<endl;
  //cout<<aOnes<<" "<<bOnes<<" "<<aZeros<<" "<<bZeros<<endl;
  if(lastNeq==0){
    isInvalid=aOnes!=aZeros;
    if(isInvalid){
      cout<<"NO"<<endl;
      return;
    }
  }elif(lastEq==0){
    isInvalid=lastNeq!=-1&&aOnes!=aZeros;
    if(isInvalid){
      cout<<"NO"<<endl;
      return;
    }
  } 
  cout<<"YES"<<endl;
}

int main(){
  fastio;
  cin>>t;
  rep(i,0,t)solve();
  return 0;
}

