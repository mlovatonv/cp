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
  string s1,s2,s3,n1,n2,n3,lens1,lens2,lens3;
  cin>>s1>>s2>>s3;
  lens1=len(s1);
  lens2=len(s2);
  lens3=len(s3);
  if(
      max(lens1,lens2)+1<lens3||
      lens3<max(lens1,lens2)||
      s3[lens3-1]==s1[lens1-1]||
      s3[lens3-1]==s2[lens2-1]
    ){
    cout<<"UNSOLVABLE"<<endl;
    return;  
  }
  char a='9',b='8'; // replacement chars
  if(max(lens1,lens2)<=lens3){
    n1+='2';
    n2+=s1[0]==s2[0]?'2':'1';
  }else{
    n1+='9';
    n2+=s1[0]==s2[0]?'9':'8';
  }
  rep(i,1,lens1){
    n1=n1+a;
  }
  rep(i,1,lens2){
    if(s1[i]==s2[i]){
      n2=n2+a;
    }else{
      n2=n2+b;
    }
  }
  char res=0,ss;
  rep(i,0,lens3){
    if(i<lens1&&s1[i]==s3[i]){
      lens1;   
    }elif(i<lens2&&s2[i]==s3[i]){
        
    }elif(i<lens1&&i<lens2){
      ss=n1[i]+n2[i]-'0'+res;
      if(ss>9){
        ss-=10;
        res=1;
      }
      s3[i]=ss;
    }elif(i<lens2){
      ss=n2[i]+res;
      if(ss>9){
        ss-=10;
        res=1;
      }
      s3[i]=ss;
    }elif(i<lens1){
      ss=n1[i]+res;
      if(ss>9){
        ss-=10;
        res=1;
      }
      s3[i]=ss;
    }
  }
  cout<<n1<<endl<<n2<<endl<<n3<<endl;
}

int main(){
  fastio;
  solve();
  return 0;
}

